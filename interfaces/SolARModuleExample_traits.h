
#ifndef MODULE_EXAMPLE_TRAITS_H
#define MODULE_EXAMPLE_TRAITS_H

#include "xpcf/api/IComponentManager.h"

namespace SolAR {
	namespace MODULES {
		namespace EXAMPLE {
			class Component1;
			class Component2;
		}
	}
}

XPCF_DEFINE_COMPONENT_TRAITS(SolAR::MODULES::EXAMPLE::Component1,
                             "59e251eb-4465-428a-986f-e62deb859343",
                             "SolAR::MODULES::EXAMPLE::Component1 definition")


XPCF_DEFINE_COMPONENT_TRAITS(SolAR::MODULES::EXAMPLE::Component2,
                             "5a5ff620-dace-4e84-861b-cd262e0310ba",
                              "SolAR::MODULES::EXAMPLE::Component2 definition")


#endif // MODULE_EXAMPLE_TRAITS_H

