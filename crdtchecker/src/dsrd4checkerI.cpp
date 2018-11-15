/*
 *    Copyright (C) 2018 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "dsrd4checkerI.h"

DSRD4checkerI::DSRD4checkerI(GenericWorker *_worker)
{
	worker = _worker;
}


DSRD4checkerI::~DSRD4checkerI()
{
}

void DSRD4checkerI::checkData(const Delta  &d, const Ice::Current&)
{
	worker->checkData(d);
}

void DSRD4checkerI::finish(const string  &name, const Ice::Current&)
{
	worker->finish(name);
}

