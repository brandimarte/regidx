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
/**  File: RI.h                                                       **/
/**                                                                   **/
/**  Description: Interface of registry index computation             **/
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


/* For calling from fortran prograns. */
#ifdef FORTRAN
#define RIreadXYZ rireadxyz_
#endif

static link head;

class Coord {
public:
   char name[2];
   double x;
   double y;
};

/* Collect required informations from coordinate 'XYZ' input files. */
void RIinit (char *exec, char *bot, char *top);

/* Read coordinate 'XYZ file. */
void RIoverlap (Coord bot, Coord top);
