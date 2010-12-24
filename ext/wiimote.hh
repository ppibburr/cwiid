/* ruby-cwiid - Wii Remote interface.
   Copyright (C) 2010 Jan Wedekind

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. */
#ifndef WIIMOTE_HH
#define WIIMOTE_HH
#include <boost/shared_ptr.hpp>
#include <cwiid.h>
#include "rubyinc.hh"
#include "error.hh"

class WiiMote
{
public:
  WiiMote(void) throw (Error);
  virtual ~WiiMote(void);
  void close(void);
  static VALUE cRubyClass;
  static VALUE registerRubyClass(void);
  static void deleteRubyObject( void *ptr );
  static VALUE wrapNew( VALUE rbClass );
  static VALUE wrapClose( VALUE rbSelf );
protected:
  cwiid_wiimote_t *m_wiimote;
};

typedef boost::shared_ptr< WiiMote > WiiMotePtr;

#endif
