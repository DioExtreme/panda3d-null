// Filename: mouse.cxx
// Created by:  mike (09Jan97)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://www.panda3d.org/license.txt .
//
// To contact the maintainers of this program write to
// panda3d@yahoogroups.com .
//
////////////////////////////////////////////////////////////////////

#include "mouse.h"

#include <mouseData.h>
#include <buttonHandle.h>
#include <buttonEvent.h>

////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////
TypeHandle MouseAndKeyboard::_type_handle;

TypeHandle MouseAndKeyboard::_pixel_xyz_type;
TypeHandle MouseAndKeyboard::_xyz_type;
TypeHandle MouseAndKeyboard::_button_events_type;


////////////////////////////////////////////////////////////////////
//     Function: MouseAndKeyboard::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
MouseAndKeyboard::
MouseAndKeyboard(GraphicsWindow *window, int device, const string& name) :
  DataNode(name),
  _window(window),
  _device(device)
{
  _pixel_xyz = new Vec3DataTransition(LPoint3f(0.0f, 0.0f, 0.0f));
  _xyz = new Vec3DataTransition(LPoint3f(0.0f, 0.0f, 0.0f));
  _button_events = new ButtonEventDataTransition();

  _got_mouse_attrib.set_transition(_pixel_xyz_type, _pixel_xyz);
  _got_mouse_attrib.set_transition(_xyz_type, _xyz);
  _got_mouse_attrib.set_transition(_button_events_type, _button_events);

  _no_mouse_attrib.set_transition(_button_events_type, _button_events);
}

////////////////////////////////////////////////////////////////////
//     Function: MouseAndKeyboard::transmit_data
//       Access: Public, Virtual
//  Description:
////////////////////////////////////////////////////////////////////
void MouseAndKeyboard::
transmit_data(AllTransitionsWrapper &data) {
  // Fill up the button events.
  _button_events->clear();
  while (_window->has_button_event(_device)) {
    ButtonEvent be = _window->get_button_event(_device);
    _button_events->push_back(be);
  }

  if (_window->has_pointer(_device)) {
    const MouseData &mdata = _window->get_mouse_data(_device);

    if (mdata._in_window) {
      // Get motion
      _pixel_xyz->set_value(LPoint3f(mdata._xpos, mdata._ypos, 0.0f));

      int w = _window->get_width();
      int h = _window->get_height();

      // Scale to range [-1,1]
      float xf = (float)(2 * mdata._xpos) / (float)w - 1.0f;
      float yf = 1.0f - (float)(2 * mdata._ypos) / (float)h;

      _xyz->set_value(LPoint3f(xf, yf, 0.0f));
      data = _got_mouse_attrib;

    } else {
      // The mouse isn't within the window right now.
      data = _no_mouse_attrib;
    }

  } else {
    // We don't have a mouse device.
    data = _no_mouse_attrib;
  }
}

////////////////////////////////////////////////////////////////////
//     Function: MouseAndKeyboard::init_type
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
void MouseAndKeyboard::
init_type() {
  DataNode::init_type();
  register_type(_type_handle, "MouseAndKeyboard",
                DataNode::get_class_type());

  Vec3DataTransition::init_type();
  register_data_transition(_pixel_xyz_type, "PixelXYZ",
                           Vec3DataTransition::get_class_type());
  register_data_transition(_xyz_type, "XYZ",
                           Vec3DataTransition::get_class_type());
  ButtonEventDataTransition::init_type();
  register_data_transition(_button_events_type, "ButtonEvents",
                           ButtonEventDataTransition::get_class_type());
}
