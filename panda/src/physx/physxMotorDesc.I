// Filename: physxMotorDesc.I
// Created by:  enn0x (28Sep09)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
//     Function: PhysxMotorDesc::Constructor
//       Access: Published
//  Description:
////////////////////////////////////////////////////////////////////
INLINE PhysxMotorDesc::
PhysxMotorDesc() {

}

////////////////////////////////////////////////////////////////////
//     Function: PhysxMotorDesc::Constructor
//       Access: Published
//  Description:
////////////////////////////////////////////////////////////////////
INLINE PhysxMotorDesc::
PhysxMotorDesc(float velTarget, float maxForce, bool freeSpin) {

  _desc.velTarget = velTarget;
  _desc.maxForce = maxForce;
  _desc.freeSpin = freeSpin;
}

////////////////////////////////////////////////////////////////////
//     Function: PhysxMotorDesc::Destructor
//       Access: Published
//  Description:
////////////////////////////////////////////////////////////////////
INLINE PhysxMotorDesc::
~PhysxMotorDesc() {

}
