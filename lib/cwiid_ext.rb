# ruby-cwiid - Wii Remote interface for Ruby.
# Copyright (C) 2010 Jan Wedekind
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
class WiiMote

  class << self

    alias_method :orig_new, :new

    def new
      retval = orig_new
      retval.rpt_mode = RPT_STATUS | RPT_BTN | RPT_ACC | RPT_IR
      retval
    end

  end

  alias_method :orig_battery, :battery

  def battery
    orig_battery.to_f / BATTERY_MAX
  end

end

