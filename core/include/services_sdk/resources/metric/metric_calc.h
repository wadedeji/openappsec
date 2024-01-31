// Copyright (C) 2022 Check Point Software Technologies Ltd. All rights reserved.

// Licensed under the Apache License, Version 2.0 (the "License");
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __METRIC_CALC_H__
#define __METRIC_CALC_H__

#ifndef __GENERIC_METRIC_H__
#error metric/metric_calc.h should not be included directly
#endif // __GENERIC_METRIC_H_

#include <cereal/archives/json.hpp>

#include "report/report.h"

class GenericMetric;

class MetricCalc
{
public:
    MetricCalc(GenericMetric *metric, const std::string &calc_title);
    virtual void reset() = 0;
    virtual void save(cereal::JSONOutputArchive &) const = 0;
    virtual LogField getLogField() const = 0;

    bool wasOnceReported() const { return was_once_reported; }

protected:
    bool was_once_reported = false;
    std::string calc_title;
};

#endif // __METRIC_CALC_H__
