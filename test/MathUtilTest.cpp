//------------------------------------------------------------------------------
//
// Copyright 2013, 2014 BBC Research and Development
//
// Author: Chris Needham
//
// This file is part of Audio Waveform Image Generator.
//
// Audio Waveform Image Generator is free software: you can redistribute it
// and/or modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation, either version 3 of the License,
// or (at your option) any later version.
//
// Audio Waveform Image Generator is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
// Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// Audio Waveform Image Generator.  If not, see <http://www.gnu.org/licenses/>.
//
//------------------------------------------------------------------------------

#include "MathUtil.h"

#include "gmock/gmock.h"

//------------------------------------------------------------------------------

using testing::Eq;
using testing::Test;

//------------------------------------------------------------------------------

TEST(MathUtilTest, shouldRoundDownToNearestInteger)
{
    ASSERT_THAT(MathUtil::roundDownToNearest(5.5, 3), Eq(3));
    ASSERT_THAT(MathUtil::roundDownToNearest(141.0, 10), Eq(140));

    // Round towards positive infinity
    ASSERT_THAT(MathUtil::roundDownToNearest(-5.5, 3), Eq(-3));

    ASSERT_THAT(MathUtil::roundDownToNearest(5.5, 0), Eq(0));
}

//------------------------------------------------------------------------------

TEST(MathUtilTest, shouldRoundUpToNearestInteger)
{
    ASSERT_THAT(MathUtil::roundUpToNearest(5.5, 3), Eq(6));
    ASSERT_THAT(MathUtil::roundUpToNearest(38.9, 5), Eq(40));
    ASSERT_THAT(MathUtil::roundUpToNearest(141.0, 10), Eq(150));

    // Round towards negative infinity
    ASSERT_THAT(MathUtil::roundUpToNearest(-5.5, 3), Eq(-6));

    ASSERT_THAT(MathUtil::roundUpToNearest(5.5, 0), Eq(0));
}

//------------------------------------------------------------------------------
