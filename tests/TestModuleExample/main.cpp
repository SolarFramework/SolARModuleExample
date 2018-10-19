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
#include <string>
#include <vector>

#include <boost/log/core.hpp>

// ADD MODULES TRAITS HEADERS HERE

#include "SolARModuleExample_traits.h"

// ADD XPCF HEADERS HERE
#include "xpcf/xpcf.h"

// ADD COMPONENTS HEADERS HERE


#include "api/example/IInterface1.h"
#include "api/example/IInterface2.h"

#include "core/Log.h"


using namespace SolAR;

int main(int argc, char **argv) {

    std::cout << "hello\n";

   LOG_ADD_LOG_TO_CONSOLE();

    #if NDEBUG
        boost::log::core::get()->set_logging_enabled(false);
    #endif

    SRef<org::bcom::xpcf::IComponentManager> xpcfComponentManager = org::bcom::xpcf::getComponentManagerInstance();

    /* instantiate component manager*/
    /* this is needed in dynamic mode */

    std::string configxml = std::string("conf_TestModuleExample.xml");
    if (argc == 2)
        configxml = std::string(argv[1]);
    if (xpcfComponentManager->load(configxml.c_str()) != org::bcom::xpcf::_SUCCESS){

        LOG_ERROR("Failed to load the configuration file {}", configxml.c_str())
        return -1;

    }
    else{

        LOG_INFO("success to load the configuration file {}", configxml.c_str())
        std::cout << "success to load the configuration file \n";

    }


    auto c1=xpcfComponentManager->create<SolAR::MODULES::EXAMPLE::Component1>()->bindTo<SolAR::api::example::IInterface1>();
    auto c2=xpcfComponentManager->create<SolAR::MODULES::EXAMPLE::Component2>()->bindTo<SolAR::api::example::IInterface2>();


    if (c1){
        c1->function1(6);
    }

    if (c2){
        c2->function2(5);
    }


    return 0;
}
