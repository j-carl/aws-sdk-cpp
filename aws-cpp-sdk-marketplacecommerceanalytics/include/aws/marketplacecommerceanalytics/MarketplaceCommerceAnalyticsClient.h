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
#include <aws/marketplacecommerceanalytics/MarketplaceCommerceAnalytics_EXPORTS.h>
#include <aws/marketplacecommerceanalytics/MarketplaceCommerceAnalyticsErrors.h>
#include <aws/core/client/AWSError.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/client/AWSClient.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/marketplacecommerceanalytics/model/GenerateDataSetResult.h>
#include <aws/core/client/AsyncCallerContext.h>
#include <aws/core/http/HttpTypes.h>
#include <future>
#include <functional>

namespace Aws
{

namespace Http
{
  class HttpClient;
  class HttpClientFactory;
} // namespace Http

namespace Utils
{
  template< typename R, typename E> class Outcome;

namespace Threading
{
  class Executor;
} // namespace Threading

namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils

namespace Auth
{
  class AWSCredentials;
  class AWSCredentialsProvider;
} // namespace Auth

namespace Client
{
  class RetryStrategy;
} // namespace Client

namespace MarketplaceCommerceAnalytics
{

namespace Model
{
        class GenerateDataSetRequest;

        typedef Aws::Utils::Outcome<GenerateDataSetResult, Aws::Client::AWSError<MarketplaceCommerceAnalyticsErrors>> GenerateDataSetOutcome;

        typedef std::future<GenerateDataSetOutcome> GenerateDataSetOutcomeCallable;
} // namespace Model

  class MarketplaceCommerceAnalyticsClient;

    typedef std::function<void(const MarketplaceCommerceAnalyticsClient*, const Model::GenerateDataSetRequest&, const Model::GenerateDataSetOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GenerateDataSetResponseReceivedHandler;

  /**
   * Provides AWS Marketplace business intelligence data on-demand.
   */
  class AWS_MARKETPLACECOMMERCEANALYTICS_API MarketplaceCommerceAnalyticsClient : public Aws::Client::AWSJsonClient
  {
    public:
      typedef Aws::Client::AWSJsonClient BASECLASS;

       /**
        * Initializes client to use DefaultCredentialProviderChain, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        MarketplaceCommerceAnalyticsClient(const Client::ClientConfiguration& clientConfiguration = Client::ClientConfiguration());

       /**
        * Initializes client to use SimpleAWSCredentialsProvider, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        MarketplaceCommerceAnalyticsClient(const Auth::AWSCredentials& credentials, const Client::ClientConfiguration& clientConfiguration = Client::ClientConfiguration());

       /**
        * Initializes client to use specified credentials provider with specified client config. If http client factory is not supplied,
        * the default http client factory will be used
        */
        MarketplaceCommerceAnalyticsClient(const std::shared_ptr<Auth::AWSCredentialsProvider>& credentialsProvider,
            const Client::ClientConfiguration& clientConfiguration = Client::ClientConfiguration(),
            const std::shared_ptr<Http::HttpClientFactory const>& httpClientFactory = nullptr);

        virtual ~MarketplaceCommerceAnalyticsClient();

        /**
         * Given a data set type and data set publication date, asynchronously publishes
         * the requested data set to the specified S3 bucket and notifies the specified SNS
         * topic once the data is available. Returns a unique request identifier that can
         * be used to correlate requests with notifications from the SNS topic. Data sets
         * will be published in comma-separated values (CSV) format with the file name
         * {data_set_type}_YYYY-MM-DD.csv. If a file with the same name already exists
         * (e.g. if the same data set is requested twice), the original file will be
         * overwritten by the new file. Requires a Role with an attached permissions policy
         * providing Allow permissions for the following actions: s3:PutObject,
         * s3:GetBucketLocation, sns:GetTopicAttributes, sns:Publish, iam:GetRolePolicy.
         */
        virtual Model::GenerateDataSetOutcome GenerateDataSet(const Model::GenerateDataSetRequest& request) const;

        /**
         * Given a data set type and data set publication date, asynchronously publishes
         * the requested data set to the specified S3 bucket and notifies the specified SNS
         * topic once the data is available. Returns a unique request identifier that can
         * be used to correlate requests with notifications from the SNS topic. Data sets
         * will be published in comma-separated values (CSV) format with the file name
         * {data_set_type}_YYYY-MM-DD.csv. If a file with the same name already exists
         * (e.g. if the same data set is requested twice), the original file will be
         * overwritten by the new file. Requires a Role with an attached permissions policy
         * providing Allow permissions for the following actions: s3:PutObject,
         * s3:GetBucketLocation, sns:GetTopicAttributes, sns:Publish, iam:GetRolePolicy.
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::GenerateDataSetOutcomeCallable GenerateDataSetCallable(const Model::GenerateDataSetRequest& request) const;

        /**
         * Given a data set type and data set publication date, asynchronously publishes
         * the requested data set to the specified S3 bucket and notifies the specified SNS
         * topic once the data is available. Returns a unique request identifier that can
         * be used to correlate requests with notifications from the SNS topic. Data sets
         * will be published in comma-separated values (CSV) format with the file name
         * {data_set_type}_YYYY-MM-DD.csv. If a file with the same name already exists
         * (e.g. if the same data set is requested twice), the original file will be
         * overwritten by the new file. Requires a Role with an attached permissions policy
         * providing Allow permissions for the following actions: s3:PutObject,
         * s3:GetBucketLocation, sns:GetTopicAttributes, sns:Publish, iam:GetRolePolicy.
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void GenerateDataSetAsync(const Model::GenerateDataSetRequest& request, const GenerateDataSetResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;


    private:
      void init(const Client::ClientConfiguration& clientConfiguration);

        /**Async helpers**/
        void GenerateDataSetAsyncHelper(const Model::GenerateDataSetRequest& request, const GenerateDataSetResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;

      Aws::String m_uri;
      std::shared_ptr<Utils::Threading::Executor> m_executor;
  };

} // namespace MarketplaceCommerceAnalytics
} // namespace Aws
