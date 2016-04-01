/*********************************************************** 
*  --- OpenSURF ---                                       *
*  This library is distributed under the GNU GPL. Please   *
*  use the contact form at http://www.chrisevansdev.com    *
*  for more information.                                   *
*                                                          *
*  C. Evans, Research Into Robust Visual Features,         *
*  MSc University of Bristol, 2008.                        *
*                                                          *
************************************************************/
#ifndef __KMEANS_H
#define  __KMEANS_H

#include "ipoint.h"

#include <vector>
#include <time.h>
#include <stdlib.h>

//-----------------------------------------------------------
// Kmeans clustering class (under development)
//  - Can be used to cluster points based on their location.
//  - Create Kmeans object and call Run with IpVec.
//  - Planned improvements include clustering based on motion 
//    and descriptor components.
//-----------------------------------------------------------

class Kmeans {

public:

  //! Destructor
  ~Kmeans() {};

  //! Constructor
  Kmeans() {};

  //! Do it all!
  void Run(IpVec *ipts, int clusters, bool init = false);

  //! Set the ipts to be used
  void SetIpoints(IpVec *ipts);

  //! Randomly distribute 'n' clusters
  void InitRandomClusters(int n);

  //! Assign Ipoints to clusters
  bool AssignToClusters();

  //! Calculate new cluster centers
  void RepositionClusters();

  //! Function to measure the distance between 2 ipoints
  float Distance(Ipoint &ip1, Ipoint &ip2);

  //! Vector stores ipoints for this run
  IpVec *ipts;

  //! Vector stores cluster centers
  IpVec clusters;

};

//-------------------------------------------------------

#endif