
include_directories(.)

add_library(turbo_lib SHARED
    tables/hash_table.cpp
    linked_lists/queue.hpp
    linked_lists/stack.hpp
    oop/design_patterns/singleton.hpp
    oop/polymorphism.hpp
    oop/object_copy.hpp
    oop/design_patterns/builder/CarProduct.hpp
    oop/design_patterns/builder/ICarBuilder.hpp
    oop/design_patterns/builder/Pipeline.hpp
    oop/design_patterns/builder/SportsCarBuilder.hpp
    oop/design_patterns/factory/domain/IAccount.hpp
    oop/design_patterns/factory/domain/IAccountFactory.hpp
    oop/design_patterns/factory/application/AccountBusiness.hpp
    oop/design_patterns/factory/application/AccountPersonal.hpp
    oop/design_patterns/factory/service/AccountBusinessCreator.hpp
    oop/design_patterns/factory/service/AccountPersonalCreator.hpp
    oop/design_patterns/dependency_injection/Car.hpp
    oop/design_patterns/dependency_injection/EnergySource.hpp
    oop/design_patterns/dependency_injection/EnergySourceBattery.hpp
    oop/design_patterns/dependency_injection/EnergySourcePetrol.hpp
    multi_threading/parallelism.cpp
    dynamic_programming/fibonacci.hpp)

set_target_properties(turbo_lib PROPERTIES LINKER_LANGUAGE CXX)
