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
#include <cstdlib>
#include <cmath>
#include "RI.hpp"

using namespace std;

const double pi = 3.1415926535897932384626433832795028841;
static atm headB;
static atm headT;
static int nS; // # of bottom C which overlap with top ones
static double S; // total overlaping area
static double rad; // radius of the C atom


/* ******************************************************************* */
/* Create a new 'Atom' and returns its pointer.                        */
static atm NEW ()
{
   int i;
   atm a;

   a = (atm) malloc (sizeof *a); /* allocate the 'Atom' */
   a->x = 0;
   a->y = 0;
   a->next = NULL;

   return a;

} /* NEW */

/* ******************************************************************* */
/* Initialize two linked lists (create their head nodes).              */
void ATinit ()
{
   headB = NEW ();
   headT = NEW ();

} /* ATinit */

/* ******************************************************************* */
/* Receive the coordinate file names from the bottom and top           */
/* structures and read those files.                                    */
void RIinit (char *exec, char *bot, char *top)
{
   register int i, len;
   char *workDir;

   /* Get the lenth of work directory path. */
   len = strlen (exec);
   for (i = len; i >= 0; i--)
      if (exec[i] == '/') break;
   len = i + 1;

   /* Assigns the work directory global variable. */
   workDir = (char *) malloc (len * sizeof (char));
   for (i = 0; i < len; i++)
      workDir[i] = exec[i];
   workDir[i] = '\0';

   /* Create two 'Atom' linked list. */
   ATinit ();

   /* Read 'bottom' xyz file. */
   RIreadXYZ (workDir, bot, headB);

   /* Read 'top' xyz file. */
   RIreadXYZ (workDir, top, headT);

   /* Free memory */
   free (workDir);

} // RIinit


/* ******************************************************************* */
/* Read coordinate 'XYZ file and store carbon coordinates in a linked  */
/* list.                                                               */
void RIreadXYZ (char *workDir, char *xyzName, atm head)
{
   register int i, n, len;
   char name[2];
   char *inputFile;
   ifstream Fxyz;
   atm item, p;
   double foo;

   /* Sets 'top' xyz file name with work directory path. */
   len = strlen (workDir) + strlen(xyzName);
   inputFile = (char *) malloc (len * sizeof (char));
   sprintf (inputFile, "%s%s", workDir, xyzName);
   Fxyz.open (inputFile, ifstream::in);

   Fxyz >> n; // # of atoms
   p = head;
   for (i = 0; i < n; i++) {
      Fxyz >> name;
      if (name[0] == 'C') { // only store xy from C atoms
	 item = NEW();
	 Fxyz >> item->x;
	 Fxyz >> item->y;
	 Fxyz >> foo;
	 p->next = item;
	 p = p->next;
      }
      else {
	 Fxyz >> foo;
	 Fxyz >> foo;
	 Fxyz >> foo;
      }
   }
   Fxyz.close ();

   free (inputFile);

} // RIreadXYZ

/* ******************************************************************* */
/* Compute the total overlap between carbons from two different        */
/* layers. The overlaping area is given by the area of two overlaping  */
/* sectors. Since we are considering only carbons (i.e. only one kind  */
/* of circle), this area is given by the two overlaping sectors.       */
/* Therefore, the overlaping area can be calculated as two times the   */
/* the area of the segment of the sector subtracted by the area of its */
/* triangle.                                                           */
void RIoverlap (char *r)
{
   // int nStop;
   double d;
   atm b, t;
   
   S = 0; // total overlaping area
   nS = 0; // # of bottom C which overlap with top ones
   // nStop = 0;
   rad = atof (r);
   b = headB;
   while (b->next != NULL) { // compare each C from bottom with...
      b = b->next;
      t = headT;
      while (t->next != NULL) { // each C from top
	 t = t->next;
	 d = RIdist (b, t);
	 if (d < 2*rad) {
	    /* 2*(A_segment - A_triangle) */
	    S += 2*rad*rad*acos(d/(2*rad))-d*sqrt(4*rad*rad-d*d)/2;
	    nS++;
	    // nStop++;
	 }
      }
   }
   // cout << nS << " " << nStop << endl;

} // RIoverlap

/* ******************************************************************* */
/* Return the distance (Euclidian metric) between two vectors in R2.   */
double RIdist (atm b, atm t)
{
   double dx, dy;

   dx = b->x - t->x;
   dy = b->y - t->y;

   return sqrt(dx*dx + dy*dy);

} // RIdist

/* ******************************************************************* */
/* Compute the registry index.                                         */
void RI ()
{
   double S_AA, S_AB, regIdx;

   S_AA = 131*pi*rad*rad; // maximum overlap case
   S_AB = 65*pi*rad*rad; // minimum overlap case

   regIdx = (S - S_AB)/(S_AA - S_AB);

   cout << S << " " << S_AA << " " << S_AB << endl;
   printf (" Registry Index: %.10f\n", regIdx);

} // RI


/* ***************************** Drafts ****************************** */

