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
/**  File: main.c                                                     **/
/**                                                                   **/
/**  Description: This is a (client) program that receives 2 'xyz'    **/
/**  files, containing the x, y and z coordinates from the carbon     **/
/**  atoms from the bottom and top structures, and compute the        **/
/**  registry index defined as:                                       **/
/**                                                                   **/
/**    RI = (S_{cc} - S^{AB}_{cc}) / (S^{AA}_{cc} - S^{AB}_{cc}),     **/
/**                                                                   **/
/**  where 'S_{cc}' is the projected overlap between circles          **/
/**  assigned to each carbon atomic center from different layers.     **/
/**  The RI is normalized considering the case with biggest           **/
/**  interlayer overlapping (worst case) which happens to be the AA   **/
/**  stacking, and the case with lowest overlapping (optimal case)    **/
/**  which happens to be the AB stacking.                             **/
/**                                                                   **/
/**  Usage: ./regidx bottom.xyz top.xyz                               **/
/**                                                                   **/
/**  Written by Pedro Brandimarte, Dec 2016.                          **/
/**  Centro de Fisica de Materiales - CFM                             **/
/**  Donostia - San Sebastian, Spain                                  **/
/**  e-mail: brandimarte@gmail.com                                    **/
/**  ***************************** HISTORY *************************  **/
/**  Original version:    January 2016                                **/
/**  ***************************************************************  **/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "RI.hpp"

using namespace std;

/* Prints the header on the screen. */
static void header ();

/* Prints the "how to run" on the screen. */
static void howto ();

int main (int nargs, char *arg[])
{
   double time;
   clock_t inicial, final;

   /* Writes the header on the screen. */
   header ();

   /* Checks if the input were typed correctly. */
   if (nargs != 4) {
      cerr << "\n Wrong number of arguments!\n";
      howto ();
      exit (EXIT_FAILURE);
   }

   /* Time is running. */
   inicial = clock();

   /* Read coordinate input files. */
   RIinit (arg[0], arg[1], arg[2]);

   /* Compute total overlap. */
   RIoverlap (arg[3]);

   /* Compute the registry index. */
   RI ();

   /* Calculates the execution time. */
   final = clock();
   time = (double)(final - inicial) / CLOCKS_PER_SEC;
   cout << "\n This calculation took " << setiosflags(ios::fixed)
	<< setprecision(2) << time << " seconds.\n\n";

   return 0;
   
} /* main */


/* ******************************************************************* */
/* Prints the header on 'stdout'.                                      */
static void header ()
{
   cout << "\n";
   cout << "**  *******************************************************"
      "******  **\n";
   cout << "**            ** WELCOME TO REGIDX C++ CODE v2016.01 **    "
      "        **\n";
   cout << "**                                                         "
      "        **\n";
   cout << "**       * Registry Index for Bilayer Carbon Based Systems "
      "*       **\n";
   cout << "**                                                         "
      "        **\n";
   cout << "**  Written by Pedro Brandimarte (brandimarte@gmail.com)   "
      "        **\n";
   cout << "**                                                         "
      "        **\n";
   cout << "**  Copyright (c), All Rights Reserved                     "
      "        **\n";
   cout << "**                                                         "
      "        **\n";
   cout << "**  This program is free software. You can redistribute it "
      "and/or  **\n";
   cout << "**  modify it under the terms of the GNU General Public "
      "License    **\n";
   cout << "**  (version 3 or later) as published by the Free Software "
      "        **\n";
   cout << "**  Foundation <http://fsf.org/>. See the GNU General "
      "Public       **\n";
   cout << "**  License for more details.                              "
      "        **\n";
   cout << "**  *******************************************************"
      "******  **\n\n";
   setvbuf (stdout, NULL, _IONBF, 0); /* print now! */

} /* header */


/* ******************************************************************* */
/* Prints the "how to run" on 'stdout'.                                */
static void howto ()
{

   cerr << "\n Usage: $ regidx"; // arg[0]
   cerr << " [bottom xyz coordinate file] \\\n"; // arg[1]
   cerr << "        > [top xyz coordinate file]"; // arg[2]
   cerr << " [circle radius (angstrom)]\n\n"; // arg[3]
   cerr << " Example: $ regidx bottom.xyz top.xyz 0.71\n\n";

} /* howto */
