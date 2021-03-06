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
#include <aws/codepipeline/CodePipeline_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/codepipeline/model/StageState.h>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace CodePipeline
{
namespace Model
{
  /**
   * <p>Represents the output of a get pipeline state action.</p>
   */
  class AWS_CODEPIPELINE_API GetPipelineStateResult
  {
  public:
    GetPipelineStateResult();
    GetPipelineStateResult(const AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    GetPipelineStateResult& operator=(const AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);

    /**
     * <p>The name of the pipeline for which you want to get the state.</p>
     */
    inline const Aws::String& GetPipelineName() const{ return m_pipelineName; }

    /**
     * <p>The name of the pipeline for which you want to get the state.</p>
     */
    inline void SetPipelineName(const Aws::String& value) { m_pipelineName = value; }

    /**
     * <p>The name of the pipeline for which you want to get the state.</p>
     */
    inline void SetPipelineName(Aws::String&& value) { m_pipelineName = value; }

    /**
     * <p>The name of the pipeline for which you want to get the state.</p>
     */
    inline void SetPipelineName(const char* value) { m_pipelineName.assign(value); }

    /**
     * <p>The name of the pipeline for which you want to get the state.</p>
     */
    inline GetPipelineStateResult& WithPipelineName(const Aws::String& value) { SetPipelineName(value); return *this;}

    /**
     * <p>The name of the pipeline for which you want to get the state.</p>
     */
    inline GetPipelineStateResult& WithPipelineName(Aws::String&& value) { SetPipelineName(value); return *this;}

    /**
     * <p>The name of the pipeline for which you want to get the state.</p>
     */
    inline GetPipelineStateResult& WithPipelineName(const char* value) { SetPipelineName(value); return *this;}

    /**
     * <p>The version number of the pipeline.</p> <note>A newly-created pipeline is
     * always assigned a version number of <code>1</code>.</note>
     */
    inline long GetPipelineVersion() const{ return m_pipelineVersion; }

    /**
     * <p>The version number of the pipeline.</p> <note>A newly-created pipeline is
     * always assigned a version number of <code>1</code>.</note>
     */
    inline void SetPipelineVersion(long value) { m_pipelineVersion = value; }

    /**
     * <p>The version number of the pipeline.</p> <note>A newly-created pipeline is
     * always assigned a version number of <code>1</code>.</note>
     */
    inline GetPipelineStateResult& WithPipelineVersion(long value) { SetPipelineVersion(value); return *this;}

    /**
     * <p>A list of the pipeline stage output information, including stage name, state,
     * most recent run details, whether the stage is disabled, and other data. </p>
     */
    inline const Aws::Vector<StageState>& GetStageStates() const{ return m_stageStates; }

    /**
     * <p>A list of the pipeline stage output information, including stage name, state,
     * most recent run details, whether the stage is disabled, and other data. </p>
     */
    inline void SetStageStates(const Aws::Vector<StageState>& value) { m_stageStates = value; }

    /**
     * <p>A list of the pipeline stage output information, including stage name, state,
     * most recent run details, whether the stage is disabled, and other data. </p>
     */
    inline void SetStageStates(Aws::Vector<StageState>&& value) { m_stageStates = value; }

    /**
     * <p>A list of the pipeline stage output information, including stage name, state,
     * most recent run details, whether the stage is disabled, and other data. </p>
     */
    inline GetPipelineStateResult& WithStageStates(const Aws::Vector<StageState>& value) { SetStageStates(value); return *this;}

    /**
     * <p>A list of the pipeline stage output information, including stage name, state,
     * most recent run details, whether the stage is disabled, and other data. </p>
     */
    inline GetPipelineStateResult& WithStageStates(Aws::Vector<StageState>&& value) { SetStageStates(value); return *this;}

    /**
     * <p>A list of the pipeline stage output information, including stage name, state,
     * most recent run details, whether the stage is disabled, and other data. </p>
     */
    inline GetPipelineStateResult& AddStageStates(const StageState& value) { m_stageStates.push_back(value); return *this; }

    /**
     * <p>A list of the pipeline stage output information, including stage name, state,
     * most recent run details, whether the stage is disabled, and other data. </p>
     */
    inline GetPipelineStateResult& AddStageStates(StageState&& value) { m_stageStates.push_back(value); return *this; }

    /**
     * <p>The date and time the pipeline was created, in timestamp format.</p>
     */
    inline double GetCreated() const{ return m_created; }

    /**
     * <p>The date and time the pipeline was created, in timestamp format.</p>
     */
    inline void SetCreated(double value) { m_created = value; }

    /**
     * <p>The date and time the pipeline was created, in timestamp format.</p>
     */
    inline GetPipelineStateResult& WithCreated(double value) { SetCreated(value); return *this;}

    /**
     * <p>The date and time the pipeline was last updated, in timestamp format.</p>
     */
    inline double GetUpdated() const{ return m_updated; }

    /**
     * <p>The date and time the pipeline was last updated, in timestamp format.</p>
     */
    inline void SetUpdated(double value) { m_updated = value; }

    /**
     * <p>The date and time the pipeline was last updated, in timestamp format.</p>
     */
    inline GetPipelineStateResult& WithUpdated(double value) { SetUpdated(value); return *this;}

  private:
    Aws::String m_pipelineName;
    long m_pipelineVersion;
    Aws::Vector<StageState> m_stageStates;
    double m_created;
    double m_updated;
  };

} // namespace Model
} // namespace CodePipeline
} // namespace Aws
