/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2013 Icinga Development Team (http://www.icinga.org/)   *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#ifndef TIMEPERIOD_H
#define TIMEPERIOD_H

#include "icinga/i2-icinga.h"
#include "icinga/timeperiod.th"
#include "base/array.h"

namespace icinga
{

/**
 * A time period.
 *
 * @ingroup icinga
 */
class I2_ICINGA_API TimePeriod : public ReflectionObjectImpl<TimePeriod>
{
public:
	DECLARE_PTR_TYPEDEFS(TimePeriod);
	DECLARE_TYPENAME(TimePeriod);

	virtual void Start(void);

	void UpdateRegion(double begin, double end, bool clearExisting);

	bool IsInside(double ts) const;
	double FindNextTransition(double begin);

	static Array::Ptr EmptyTimePeriodUpdate(const TimePeriod::Ptr& tp, double begin, double end);
	static Array::Ptr EvenMinutesTimePeriodUpdate(const TimePeriod::Ptr& tp, double begin, double end);

private:
	void AddSegment(double s, double end);
	void AddSegment(const Dictionary::Ptr& segment);
	void RemoveSegment(double begin, double end);
	void PurgeSegments(double end);

	void Dump(void);

	static void UpdateTimerHandler(void);
};

}

#endif /* TIMEPERIOD_H */
