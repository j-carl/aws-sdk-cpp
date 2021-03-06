/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#pragma once
#include <aws/elasticmapreduce/EMR_EXPORTS.h>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace EMR
{
namespace Model
{

  /**
   * <p>The timeline of the instance group lifecycle.</p>
   */
  class AWS_EMR_API InstanceGroupTimeline
  {
  public:
    InstanceGroupTimeline();
    InstanceGroupTimeline(const Aws::Utils::Json::JsonValue& jsonValue);
    InstanceGroupTimeline& operator=(const Aws::Utils::Json::JsonValue& jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;

    /**
     * <p>The creation date and time of the instance group.</p>
     */
    inline double GetCreationDateTime() const{ return m_creationDateTime; }

    /**
     * <p>The creation date and time of the instance group.</p>
     */
    inline void SetCreationDateTime(double value) { m_creationDateTimeHasBeenSet = true; m_creationDateTime = value; }

    /**
     * <p>The creation date and time of the instance group.</p>
     */
    inline InstanceGroupTimeline& WithCreationDateTime(double value) { SetCreationDateTime(value); return *this;}

    /**
     * <p>The date and time when the instance group became ready to perform tasks.</p>
     */
    inline double GetReadyDateTime() const{ return m_readyDateTime; }

    /**
     * <p>The date and time when the instance group became ready to perform tasks.</p>
     */
    inline void SetReadyDateTime(double value) { m_readyDateTimeHasBeenSet = true; m_readyDateTime = value; }

    /**
     * <p>The date and time when the instance group became ready to perform tasks.</p>
     */
    inline InstanceGroupTimeline& WithReadyDateTime(double value) { SetReadyDateTime(value); return *this;}

    /**
     * <p>The date and time when the instance group terminated.</p>
     */
    inline double GetEndDateTime() const{ return m_endDateTime; }

    /**
     * <p>The date and time when the instance group terminated.</p>
     */
    inline void SetEndDateTime(double value) { m_endDateTimeHasBeenSet = true; m_endDateTime = value; }

    /**
     * <p>The date and time when the instance group terminated.</p>
     */
    inline InstanceGroupTimeline& WithEndDateTime(double value) { SetEndDateTime(value); return *this;}

  private:
    double m_creationDateTime;
    bool m_creationDateTimeHasBeenSet;
    double m_readyDateTime;
    bool m_readyDateTimeHasBeenSet;
    double m_endDateTime;
    bool m_endDateTimeHasBeenSet;
  };

} // namespace Model
} // namespace EMR
} // namespace Aws
