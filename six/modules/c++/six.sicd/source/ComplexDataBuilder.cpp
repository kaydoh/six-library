/* =========================================================================
 * This file is part of six.sicd-c++
 * =========================================================================
 *
 * (C) Copyright 2004 - 2014, MDA Information Systems LLC
 *
 * six.sicd-c++ is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; If not,
 * see <http://www.gnu.org/licenses/>.
 *
 */
#include "six/sicd/ComplexDataBuilder.h"

using namespace six;
using namespace six::sicd;

ComplexDataBuilder::ComplexDataBuilder() :
    mData(new ComplexData()), mAdopt(true)
{
}

ComplexDataBuilder::ComplexDataBuilder(ComplexData *data) :
    mData(data), mAdopt(false)
{
}

ComplexDataBuilder::~ComplexDataBuilder()
{
    if (mData && mAdopt)
        delete mData;
}

ComplexDataBuilder& ComplexDataBuilder::addImageCreation()
{
    mData->imageCreation.reset(new ImageCreation());
    return *this;
}

ComplexDataBuilder& ComplexDataBuilder::addRadiometric()
{
    mData->radiometric.reset(new Radiometric());
    return *this;
}

ComplexDataBuilder& ComplexDataBuilder::addAntenna()
{
    mData->antenna.reset(new Antenna());
    return *this;
}

ComplexDataBuilder& ComplexDataBuilder::addErrorStatistics()
{
    mData->errorStatistics.reset(new ErrorStatistics());
    return *this;
}

ComplexDataBuilder& ComplexDataBuilder::addMatchInformation()
{
    mData->matchInformation.reset(new MatchInformation());
    return *this;
}

ComplexData* ComplexDataBuilder::get()
{
    return mData;
}

ComplexData* ComplexDataBuilder::steal()
{
    mAdopt = false;
    return get();
}

