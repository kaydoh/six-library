/* =========================================================================
 * This file is part of six-c++ 
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2009, General Dynamics - Advanced Information Systems
 *
 * six-c++ is free software; you can redistribute it and/or modify
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
#ifndef __SIX_UTILITIES_H__
#define __SIX_UTILITIES_H__

#include "six/Types.h"
#include "six/DerivedData.h"
#include "scene/SceneGeometry.h"
#include <import/io.h>
#include <import/xml/lite.h>
#include <import/str.h>

namespace six
{

struct Utilities
{

    /*!
     *  Analyze the NITF's image subheader and give us back a pixel type
     *  TODO: Put me in NITFImageInfo
     */
    static PixelType getNITFPixelType(nitf::ImageSubheader& subheader);

    /*!
     *  Create a scene geometry object from the derived data passed in
     *
     */
    static scene::SceneGeometry* getSceneGeometry(DerivedData* derived);

    //!  Set the geometry/collection params in the derived section
    //!  based on minimal scene information
    static void setSceneGeometryValues(DerivedData* derived);

    //!  Set the values section given minimal scene information
    static void setProductValues(six::Poly2D timeCOAPoly, six::PolyXYZ arpPoly,
            six::ReferencePoint ref, six::Vector3* row, six::Vector3* col,
            six::RangeAzimuth res, six::Product* product);

    //!  Set the values section given minimal scene information
    static void setProductValues(six::Vector3 arpVel, six::Vector3 arpPos,
            six::Vector3 refPos, six::Vector3* row, six::Vector3* col,
            six::RangeAzimuth res, six::Product* product);

    //!  Set the values section given minimal scene information
    static void setCollectionValues(six::Poly2D timeCOAPoly,
            six::PolyXYZ arpPoly, six::ReferencePoint ref, six::Vector3* row,
            six::Vector3* col, six::Collection* collection);

    //!  Set the values section given minimal scene information
    static void setCollectionValues(six::Vector3 arpVel, six::Vector3 arpPos,
            six::Vector3 refPos, six::Vector3* row, six::Vector3* col,
            six::Collection* collection);

};
}

//extend the str namespace to have some useful converters
namespace str
{
template<> six::EarthModelType toType<six::EarthModelType> (
        const std::string& s);
template<> six::MagnificationMethod toType<six::MagnificationMethod> (
        const std::string& s);
template<> std::string toString(const six::MagnificationMethod& value);
template<> six::MagnificationMethod toType<six::MagnificationMethod> (
        const std::string& s);
template<> six::DecimationMethod toType<six::DecimationMethod> (
        const std::string& s);
template<> std::string toString(const six::DecimationMethod& value);

template<> six::PixelType toType<six::PixelType> (const std::string& s);
template<> std::string toString(const six::PixelType& value);

template<> six::RadarModeType toType<six::RadarModeType> (const std::string& s);
template<> std::string toString(const six::RadarModeType& value);

template<> six::DateTime toType<six::DateTime> (const std::string& s);
template<> std::string toString(const six::DateTime& value);

template<> std::string toString(const six::DataClass& value);
template<> std::string toString(const six::DataType& value);
template<> std::string toString(const six::EarthModelType& value);
template<> six::PolarizationType toType<six::PolarizationType> (
        const std::string& s);
template<> std::string toString(const six::PolarizationType& value);

template<> std::string toString(const six::DualPolarizationType& value);
template<> six::DualPolarizationType toType<six::DualPolarizationType> (
        const std::string& s);
template<> six::DemodType toType<six::DemodType> (const std::string& s);
template<> std::string toString(const six::DemodType& value);

template<> std::string toString(const six::ImageFormationType& value);
template<> six::ImageFormationType toType<six::ImageFormationType> (
        const std::string& s);
template<> std::string toString(const six::SlowTimeBeamCompensationType& value);
template<> six::SlowTimeBeamCompensationType toType<
        six::SlowTimeBeamCompensationType> (const std::string& s);
template<> std::string toString(const six::ImageBeamCompensationType& value);
template<> six::ImageBeamCompensationType
        toType<six::ImageBeamCompensationType> (const std::string& s);
template<> std::string toString(const six::AutofocusType& value);
template<> six::AutofocusType toType<six::AutofocusType> (const std::string& s);
template<> six::PosVelError::FrameType toType<six::PosVelError::FrameType> (
        const std::string& s);
template<> std::string toString(const six::SideOfTrackType& value);

//! THIS SHOULD ONLY BE USED WHEN THE TYPE IS REALLY A booleantype!
template<> six::BooleanType toType<six::BooleanType> (const std::string& s);
template<> bool toType<bool> (const std::string& s);
template<> six::SideOfTrackType toType<six::SideOfTrackType> (
        const std::string& s);

template<> six::ComplexImagePlaneType toType<six::ComplexImagePlaneType> (
        const std::string& s);
template<> std::string toString(const six::ComplexImagePlaneType& value);

template<> six::ComplexImageGridType toType<six::ComplexImageGridType> (
        const std::string& s);
template<> std::string toString(const six::ComplexImageGridType& value);

template<> six::FFTSign toType<six::FFTSign> (const std::string& s);
template<> std::string toString(const six::FFTSign& value);

template<> six::AppliedType toType<six::AppliedType> (const std::string& s);
template<> std::string toString(const six::AppliedType& value);

template<> six::CollectType toType<six::CollectType> (const std::string& s);
template<> std::string toString(const six::CollectType& value);
}

#endif