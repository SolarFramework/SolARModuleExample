#include "xpcf/module/ModuleFactory.h"

#include "Component1.h"
#include "Component2.h"

namespace xpcf=org::bcom::xpcf;

XPCF_DECLARE_MODULE("afab90cb-b358-4222-aab1-2558d59ef4db", "SolarModuleExample", "SolarModuleExample module");


extern "C" XPCF_MODULEHOOKS_API xpcf::XPCFErrorCode XPCF_getComponent(const boost::uuids::uuid& componentUUID,SRef<xpcf::IComponentIntrospect>& interfaceRef)
{
    xpcf::XPCFErrorCode errCode = xpcf::XPCFErrorCode::_FAIL;
    errCode = xpcf::tryCreateComponent<SolAR::MODULES::EXAMPLE::Component1>(componentUUID,interfaceRef);
    if (errCode != xpcf::XPCFErrorCode::_SUCCESS)
    {
        errCode = xpcf::tryCreateComponent<SolAR::MODULES::EXAMPLE::Component2>(componentUUID,interfaceRef);
    }
    return errCode;
}

XPCF_BEGIN_COMPONENTS_DECLARATION
XPCF_ADD_COMPONENT(SolAR::MODULES::EXAMPLE::Component1)
XPCF_ADD_COMPONENT(SolAR::MODULES::EXAMPLE::Component2)
XPCF_END_COMPONENTS_DECLARATION
