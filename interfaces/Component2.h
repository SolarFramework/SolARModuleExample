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

#ifndef EXAMPLECOMPONENT2_H
#define EXAMPLECOMPONENT2_H

#include "api/example/IInterface2.h"

#include "xpcf/component/ConfigurableBase.h"
#include "SolARModuleExampleAPI.h"

namespace SolAR {
	namespace MODULES {
		namespace EXAMPLE {

			class EXAMPLE_EXPORT_API Component2 : public org::bcom::xpcf::ConfigurableBase,
                                                  public api::example::IInterface2
			{
				public:
                    Component2();
                    ~Component2();

//                    org::bcom::xpcf::XPCFErrorCode onConfigured() override final;
                    void unloadComponent () override final;

                    FrameworkReturnCode function2(int var) override;

				private:

			};

		}
	}
}

#endif // EXAMPLECOMPONENT2_H
