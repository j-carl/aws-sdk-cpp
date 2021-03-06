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
#include <aws/s3/model/LifecycleRule.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::S3::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

LifecycleRule::LifecycleRule() : 
    m_expirationHasBeenSet(false),
    m_iDHasBeenSet(false),
    m_prefixHasBeenSet(false),
    m_statusHasBeenSet(false),
    m_transitionsHasBeenSet(false),
    m_noncurrentVersionTransitionsHasBeenSet(false),
    m_noncurrentVersionExpirationHasBeenSet(false)
{
}

LifecycleRule::LifecycleRule(const XmlNode& xmlNode) : 
    m_expirationHasBeenSet(false),
    m_iDHasBeenSet(false),
    m_prefixHasBeenSet(false),
    m_statusHasBeenSet(false),
    m_transitionsHasBeenSet(false),
    m_noncurrentVersionTransitionsHasBeenSet(false),
    m_noncurrentVersionExpirationHasBeenSet(false)
{
  *this = xmlNode;
}

LifecycleRule& LifecycleRule::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode expirationNode = resultNode.FirstChild("Expiration");
    if(!expirationNode.IsNull())
    {
      m_expiration = expirationNode;
      m_expirationHasBeenSet = true;
    }
    XmlNode iDNode = resultNode.FirstChild("ID");
    if(!iDNode.IsNull())
    {
      m_iD = StringUtils::Trim(iDNode.GetText().c_str());
      m_iDHasBeenSet = true;
    }
    XmlNode prefixNode = resultNode.FirstChild("Prefix");
    if(!prefixNode.IsNull())
    {
      m_prefix = StringUtils::Trim(prefixNode.GetText().c_str());
      m_prefixHasBeenSet = true;
    }
    XmlNode statusNode = resultNode.FirstChild("Status");
    if(!statusNode.IsNull())
    {
      m_status = ExpirationStatusMapper::GetExpirationStatusForName(StringUtils::Trim(statusNode.GetText().c_str()).c_str());
      m_statusHasBeenSet = true;
    }
    XmlNode transitionsNode = resultNode.FirstChild("Transitions");
    if(!transitionsNode.IsNull())
    {
      XmlNode transitionsMember = transitionsNode;
      while(!transitionsMember.IsNull())
      {
        m_transitions.push_back(transitionsMember);
        transitionsMember = transitionsMember.NextNode("Transition");
      }

      m_transitionsHasBeenSet = true;
    }
    XmlNode noncurrentVersionTransitionsNode = resultNode.FirstChild("NoncurrentVersionTransitions");
    if(!noncurrentVersionTransitionsNode.IsNull())
    {
      XmlNode noncurrentVersionTransitionsMember = noncurrentVersionTransitionsNode;
      while(!noncurrentVersionTransitionsMember.IsNull())
      {
        m_noncurrentVersionTransitions.push_back(noncurrentVersionTransitionsMember);
        noncurrentVersionTransitionsMember = noncurrentVersionTransitionsMember.NextNode("NoncurrentVersionTransition");
      }

      m_noncurrentVersionTransitionsHasBeenSet = true;
    }
    XmlNode noncurrentVersionExpirationNode = resultNode.FirstChild("NoncurrentVersionExpiration");
    if(!noncurrentVersionExpirationNode.IsNull())
    {
      m_noncurrentVersionExpiration = noncurrentVersionExpirationNode;
      m_noncurrentVersionExpirationHasBeenSet = true;
    }
  }

  return *this;
}

void LifecycleRule::AddToNode(XmlNode& parentNode) const
{
  Aws::StringStream ss;
  if(m_expirationHasBeenSet)
  {
   XmlNode expirationNode = parentNode.CreateChildElement("Expiration");
   m_expiration.AddToNode(expirationNode);
  }

  if(m_iDHasBeenSet)
  {
   XmlNode iDNode = parentNode.CreateChildElement("ID");
   iDNode.SetText(m_iD);
  }

  if(m_prefixHasBeenSet)
  {
   XmlNode prefixNode = parentNode.CreateChildElement("Prefix");
   prefixNode.SetText(m_prefix);
  }

  if(m_statusHasBeenSet)
  {
   XmlNode statusNode = parentNode.CreateChildElement("Status");
   statusNode.SetText(ExpirationStatusMapper::GetNameForExpirationStatus(m_status));
  }

  if(m_transitionsHasBeenSet)
  {
   for(const auto& item : m_transitions)
   {
     XmlNode transitionsNode = parentNode.CreateChildElement("Transition");
     item.AddToNode(transitionsNode);
   }
  }

  if(m_noncurrentVersionTransitionsHasBeenSet)
  {
   for(const auto& item : m_noncurrentVersionTransitions)
   {
     XmlNode noncurrentVersionTransitionsNode = parentNode.CreateChildElement("NoncurrentVersionTransition");
     item.AddToNode(noncurrentVersionTransitionsNode);
   }
  }

  if(m_noncurrentVersionExpirationHasBeenSet)
  {
   XmlNode noncurrentVersionExpirationNode = parentNode.CreateChildElement("NoncurrentVersionTransition");
   m_noncurrentVersionExpiration.AddToNode(noncurrentVersionExpirationNode);
  }

}
