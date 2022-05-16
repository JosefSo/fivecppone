#include <iostream>
#include <string>
#include <vector>
#include "OrgChart.hpp"
#include "doctest.h"


using namespace ariel;

TEST_CASE("good"){

    OrgChart organization;

    CHECK_NOTHROW(organization.add_root("CEO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));         // Now the CTO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));         // Now the CFO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));     // Now the COO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW")); // Now the VP Software is subordinate to the CTO
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));      // Now the VP_BI is subordinate to the COO

    CHECK_NOTHROW(organization.add_root("CEO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));         // Now the CTO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));         // Now the CFO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));     // Now the COO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW")); // Now the VP Software is subordinate to the CTO
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));      // Now the VP_BI is subordinate to the COO

}

TEST_CASE("bad"){
    OrgChart organization;
    organization.add_root("CEO");

    CHECK_THROWS(organization.add_sub("NoName", "CTO"));
    CHECK_THROWS(organization.add_sub("NoName", "CTO"));
    CHECK_THROWS(organization.add_sub("NoName", "CTO"));
    CHECK_THROWS(organization.add_sub("NoName", "CTO"));
    CHECK_THROWS(organization.add_sub("NoName", "CTO"));
    CHECK_THROWS(organization.add_sub("NoName", "CTO"));
    CHECK_THROWS(organization.add_sub("NoName", "CTO"));
    CHECK_THROWS(organization.add_sub("NoName", "CTO"));
    CHECK_THROWS(organization.add_sub("NoName", "CTO"));
}