// ndppd - NDP Proxy Daemon
// Copyright (C) 2011  Daniel Adolfsson
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ndppd.h"
#include "rule.h"
#include "proxy.h"
#include "iface.h"

__NDPPD_NS_BEGIN

rule::rule()
{
}

ptr<rule> rule::create(const ptr<proxy>& pr, const address& addr, const ptr<iface>& ifa)
{
   ptr<rule> ru(new rule());
   ru->_weak_ptr = ru.weak_copy();
   ru->_pr       = pr;
   ru->_ifa      = ifa;
   ru->_addr     = addr;

   DBG("rule addr set to %s", addr.to_string().c_str());

   return ru;
}

ptr<rule> rule::create(const ptr<proxy>& pr, const address& addr)
{
   ptr<rule> ru(new rule());
   ru->_weak_ptr = ru.weak_copy();
   ru->_pr       = pr;
   ru->_addr     = addr;

   DBG("rule addr set to %s", addr.to_string().c_str());

   return ru;
}

const address& rule::addr() const
{
   DBG("rule addr set to %s", _addr.to_string().c_str());
   return _addr;
}

ptr<iface> rule::ifa() const
{
   return _ifa;
}

bool rule::is_static() const
{
   return !!_ifa;
}

bool rule::check(const address& addr) const
{
   return _addr == addr;
}

__NDPPD_NS_END
 
 