/**  ***************************************************************  **/
/**  regidx C++ code - 2016                                           **/
/**                                                                   **/
/**       ** Registry Index for Bilayer Carbon Based Systems **       **/
/**                                                                   **/
/**  Written by Pedro Brandimarte (brandimarte@gmail.com)             **/
/**                                                                   **/
/**  Copyright (c), All Rights Reserved                               **/
/**                                                                   **/
/**  This program is free software. You can redistribute it and/or    **/
/**  modify it under the terms of the GNU General Public License      **/
/**  (version 3 or later) as published by the Free Software           **/
/**  Foundation <http://fsf.org/>.                                    **/
/**                                                                   **/
/**  This program is distributed in the hope that it will be useful,  **/
/**  but WITHOUT ANY WARRANTY, without even the implied warranty of   **/
/**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the     **/
/**  GNU General Public License for more details (file 'LICENSE_GPL'  **/
/**  distributed along with this program or at                        **/
/**  <http://www.gnu.org/licenses/gpl.html>).                         **/
/**  ***************************************************************  **/
/**  File: RI.cpp                                                     **/
/**                                                                   **/
/**  Description: Implementation of registry index computation        **/
/**                                                                   **/
/**   - reads the coordinates from bottom and top structures from     **/
/**   two given xyz input files;                                      **/
/**                                                                   **/
/**  Written by Pedro Brandimarte, Dec 2016.                          **/
/**  Centro de Fisica de Materiales - CFM                             **/
/**  Donostia - San Sebastian, Spain                                  **/
/**  e-mail: brandimarte@gmail.com                                    **/
/**  ***************************** HISTORY *************************  **/
/**  Original version:    January 2016                                **/
/**  ***************************************************************  **/

#include <iostream>
#include <cstring>
#include <fstream>
#include "RI.h"
#include "Check.h"

using namespace std;

static char *workDir; /* work directory */

typedef struct Atom *atm;
struct Atom{ double x; double y; atm *next; };

static atm headB;
static atm headT;

/* ******************************************************************* */
/* Create a new 'Atom' and returns its pointer.                        */
static atm NEW ()
{
   int i;
   atm a;

   a = (atm *) CHECKmalloc (sizeof *a); /* allocate the 'Atom' */
   a->x = 0;
   a->y = 0;
   a->next = NULL;

   return a;

} /* NEW */

/* ******************************************************************* */
/* Initialize two linked lists (create their head nodes).              */
void ATinit ()
{
   headB = NEW (); /* creates the head node */
   headT = NEW (); /* creates the head node */

} /* ATinit */

/* ******************************************************************* */
/* Receive the coordinate file names from the bottom and top           */
/* structures and read those files.                                    */
void RIinit (char *exec, char *bot, char *top)
{
   register int i, j, len;
   int nBot, nTop;
   Coord *xyBot, *xyTop;
   char *inputFile;
   ifstream Fxyz;
   double foo;

   /* Get the lenth of work directory path. */
   len = strlen (exec);
   for (i = len; i >= 0; i--)
      if (exec[i] == '/') break;
   len = i + 1;

   /* Assigns the work directory global variable. */
   workDir = (char *) CHECKmalloc (len * sizeof (char));
   for (i = 0; i < len; i++)
      workDir[i] = exec[i];
   workDir[i] = '\0';

   /* Create two 'Atom' linked list. */
   ATinit ();

   /* Sets 'bottom' xyz file name with work directory path. */
   len = strlen (workDir) + strlen(bot);
   inputFile = (char *) CHECKmalloc (len * sizeof (char));
   sprintf (inputFile, "%s%s", workDir, bot);
   Fxyz.open (inputFile, ifstream::in);
   Fxyz >> nBot; // # bottom of atoms
   xyBot = new Coord[nBot];
   for (i = 0; i < nBot; i++) {
      Fxyz >> foo1;
      Fxyz >> xyBot[i].x;
      Fxyz >> xyBot[i].y;
      Fxyz >> foo2;
   }
   Fxyz.close ();
   free (inputFile);

   /* Sets 'top' xyz file name with work directory path. */
   len = strlen (workDir) + strlen(top);
   inputFile = (char *) CHECKmalloc (len * sizeof (char));
   sprintf (inputFile, "%s%s", workDir, top);
   Fxyz.open (inputFile, ifstream::in);
   Fxyz >> nTop; // # top of atoms
   xyTop = new Coord[nTop];
   for (i = 0; i < nTop; i++) {
      Fxyz >> xyTop[i].chel;
      Fxyz >> xyTop[i].x;
      Fxyz >> xyTop[i].y;
      Fxyz >> foo;
   }
   Fxyz.close ();
   free (inputFile);

   for (i = 0; i < nTop; i++)
      RIoverlap (xyBot[i], xyTop[i]);

} // RIinit

/* ******************************************************************* */
void RIoverlap (Coord bot, Coord top)
{
   // register int i;

   cout << bot.x << "  " << bot.y << "  " << top.x << "  " << top.y << endl;


} // RIoverlap

/* ***************************** Drafts ****************************** */

