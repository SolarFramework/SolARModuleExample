/**
 * @copyright Copyright (c) 2017 B-com http://www.b-com.com/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>

#include "Component1.h"
#
namespace xpcf  = org::bcom::xpcf;

XPCF_DEFINE_FACTORY_CREATE_INSTANCE(SolAR::MODULES::EXAMPLE::Component1)

namespace SolAR {
	namespace MODULES {
		namespace EXAMPLE {
			
			Component1::Component1():ConfigurableBase(xpcf::toUUID<Component1>()){
               addInterface<api::example::IInterface1>(this);
			   SRef<xpcf::IPropertyMap> params = getPropertyRootNode();
			   LOG_DEBUG(" Component1 constructor");
			}

            Component1::~Component1()
            {
                LOG_DEBUG(" Component1 destructor")
            }

            FrameworkReturnCode Component1::function1(int var){
                std::cout << "Component 1 : var = " << var << "\n";
                return FrameworkReturnCode::_SUCCESS;

			}
			
		}
	}
}
