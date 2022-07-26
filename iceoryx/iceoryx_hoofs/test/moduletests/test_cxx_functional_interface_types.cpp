// Copyright (c) 2022 by Apex.AI Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#include "test_cxx_functional_interface_types.hpp"

namespace test_cxx_functional_interface
{
//////////////////////////////////
/// BEGIN GenericValueErrorFactory
//////////////////////////////////
GenericValueErrorFactory::value_t GenericValueErrorFactory::usedTestValue = 1;
GenericValueErrorFactory::value_t GenericValueErrorFactory::anotherTestValue = 2;
GenericValueErrorFactory::error_t GenericValueErrorFactory::usedErrorValue = 3;
GenericValueErrorFactory::error_t GenericValueErrorFactory::anotherErrorValue = 4;

void GenericValueErrorFactory::configureNextTestCase() noexcept
{
    // we increment all the values with an arbitrary value (23) int every test case
    // so that we have some variation with every test and reduce the false positives
    // probability due to memory corruptions
    usedTestValue += 23;
    anotherTestValue += 23;
    usedErrorValue += 23;
    anotherErrorValue += 23;
}

GenericValueErrorFactory::Type GenericValueErrorFactory::createValidObject() noexcept
{
    return GenericValueError(usedTestValue, usedErrorValue);
}

GenericValueErrorFactory::Type GenericValueErrorFactory::createInvalidObject() noexcept
{
    return GenericValueError(GenericValueError::INVALID_VALUE, usedErrorValue);
}
//////////////////////////////////
/// END GenericValueErrorFactory
//////////////////////////////////

/////////////////////////////
/// BEGIN GenericPlainFactory
/////////////////////////////
void GenericPlainFactory::configureNextTestCase() noexcept
{
}

GenericPlain GenericPlainFactory::createValidObject() noexcept
{
    return GenericPlain(GenericPlain::VALID_VALUE, GenericPlain::VALID_VALUE);
}

GenericPlain GenericPlainFactory::createInvalidObject() noexcept
{
    return GenericPlain(GenericPlain::INVALID_VALUE, GenericPlain::INVALID_VALUE);
}
///////////////////////////
/// END GenericPlainFactory
///////////////////////////

/////////////////////////
/// BEGIN OptionalFactory
/////////////////////////
OptionalFactory::value_t OptionalFactory::usedTestValue = 56;
OptionalFactory::value_t OptionalFactory::anotherTestValue = 1174;

void OptionalFactory::configureNextTestCase() noexcept
{
    // we increment all the values with an arbitrary value every test case
    // so that we have some variation with every test and reduce the false positives
    // probability due to memory corruptions
    usedTestValue += 67;
    anotherTestValue += 69;
}

OptionalFactory::Type OptionalFactory::createValidObject() noexcept
{
    return OptionalFactory::Type(iox::cxx::in_place, usedTestValue);
}

OptionalFactory::Type OptionalFactory::createInvalidObject() noexcept
{
    return iox::cxx::nullopt;
}
///////////////////////
/// END OptionalFactory
///////////////////////

//////////////////////////////////
/// BEGIN ExpectedValueErrorFactory
//////////////////////////////////
ExpectedValueErrorFactory::value_t ExpectedValueErrorFactory::usedTestValue = 11;
ExpectedValueErrorFactory::value_t ExpectedValueErrorFactory::anotherTestValue = 12;
ExpectedValueErrorFactory::error_t ExpectedValueErrorFactory::usedErrorValue = 13;
ExpectedValueErrorFactory::error_t ExpectedValueErrorFactory::anotherErrorValue = 14;

void ExpectedValueErrorFactory::configureNextTestCase() noexcept
{
    // we increment all the values with an static arbitrary value in every test case
    // so that we have some variation with every test and reduce the false positives
    // probability due to memory corruptions
    usedTestValue += 189;
    anotherTestValue += 189;
    usedErrorValue += 191;
    anotherErrorValue += 191;
}

ExpectedValueErrorFactory::Type ExpectedValueErrorFactory::createValidObject() noexcept
{
    return iox::cxx::success<uint64_t>(usedTestValue);
}

ExpectedValueErrorFactory::Type ExpectedValueErrorFactory::createInvalidObject() noexcept
{
    return iox::cxx::error<uint64_t>(usedErrorValue);
}
//////////////////////////////////
/// END ExpectedValueErrorFactory
//////////////////////////////////

//////////////////////////////
/// BEGIN ExpectedErrorFactory
//////////////////////////////
ExpectedErrorFactory::error_t ExpectedErrorFactory::usedErrorValue = 13;
ExpectedErrorFactory::error_t ExpectedErrorFactory::anotherErrorValue = 14;

void ExpectedErrorFactory::configureNextTestCase() noexcept
{
    // we increment all the values with an static arbitrary value in every test case
    // so that we have some variation with every test and reduce the false positives
    // probability due to memory corruptions
    usedErrorValue += 191;
    anotherErrorValue += 191;
}

ExpectedErrorFactory::Type ExpectedErrorFactory::createValidObject() noexcept
{
    return iox::cxx::success<>();
}

ExpectedErrorFactory::Type ExpectedErrorFactory::createInvalidObject() noexcept
{
    return iox::cxx::error<uint64_t>(usedErrorValue);
}
////////////////////////////
/// END ExpectedErrorFactory
////////////////////////////


} // namespace test_cxx_functional_interface
