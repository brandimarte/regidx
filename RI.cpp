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

/* ******************************************************************* */
/* Receive the coordinate file names from the bottom and top           */
/* structures and read those files.                                    */
void RIinit (char *exec, char *bot, char *top)
{
   register int i, len;
   int nBot, nTop;
   Coord *xyBot, *xyTop;
   char *inputFile;
   ifstream Fxyz;
   char foo1;
   double foo2;

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

   /* Sets the bottom xyz file name with work directory path. */
   len = strlen (workDir) + strlen(bot);
   inputFile = (char *) CHECKmalloc (len * sizeof (char));
   sprintf (inputFile, "%s%s", workDir, bot);
   Fxyz.open (inputFile, ifstream::in);
   Fxyz >> nBot; // # of atoms
   xyBot = new Coord[nBot];
   for (i = 0; i < nBot; i++) {
      Fxyz >> foo1;
      Fxyz >> xyBot[i].x;
      Fxyz >> xyBot[i].y;
      Fxyz >> foo2;
   }
   Fxyz.close ();
   for (i = 0; i < nBot; i++) {
      printf ("%d  %f  %f\n", i+1, xyBot[i].x, xyBot[i].y);
   }

   /* Free memory. */
   free (inputFile);


} // RIinit

/* ******************************************************************* */
/* Receive a coordinate file and reads the structure size 'n' and the  */
/* 'x' and 'y' coordinates.                                            */
void RIreadXYZ (char *file, int *n, Coord *xy)
{
   register int i;
   ifstream Fxyz;
   char foo1;
   double foo2;

   Fxyz.open (file, ifstream::in);

   Fxyz >> *n; // # of atoms

   xy = new Coord[*n];
   for (i = 0; i < *n; i++) {
      Fxyz >> foo1;
      Fxyz >> xy[i].x;
      Fxyz >> xy[i].y;
      Fxyz >> foo2;
   }

   Fxyz.close ();


} // RIreadXYZ

/* ***************************** Drafts ****************************** */

