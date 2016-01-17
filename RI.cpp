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
#include "RI.h"
#include "Check.h"

using namespace std;

static char *workDir; /* work directory */


/* ******************************************************************* */
/* Receive the coordinate file names from the bottom and top           */
/* structures and read those files.                                    */
void RIreadXYZ (char *exec, char *bot, char *top)
{
   register int i, len;

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


} /* RIreadXYZ */


/* ***************************** Drafts ****************************** */

