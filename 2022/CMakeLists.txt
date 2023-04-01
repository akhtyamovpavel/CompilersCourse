project(Compilers2022)
set(CURRENT_EXECUTABLE "${PROJECT_NAME}Executable")
set(GRAMMAR_LIB "${PROJECT_NAME}GrammarLib")
set(GRAMMAR_PROJECT "${PROJECT_NAME}GrammarProject")

if (APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=lld")
endif()

find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


set(
        SOURCES
        driver.cpp
#        visitors/Interpreter.cpp
        visitors/TemplateVisitor.cpp
        visitors/PrintVisitor.cpp
        visitors/MainInterpreter.cpp
        visitors/MainInterpreter.h
        visitors/IrGeneratorVisitor.h
        visitors/IrGeneratorVisitor.cpp
        visitors/SymbolTableVisitor.h
        visitors/SymbolTableVisitor.cpp
        symbols/BaseSymbol.cpp symbols/BaseSymbol.h
        symbols/Function.cpp symbols/VariableSymbol.cpp
        scopes/BaseScope.cpp scopes/BaseScope.h)

add_subdirectory(grammar)

add_executable(
        ${CURRENT_EXECUTABLE}
        main.cpp
        ${SOURCES}
)

add_executable(
        ${CURRENT_EXECUTABLE}_tests
        test_scope.cpp
        ${SOURCES}
)

add_executable(
    ${CURRENT_EXECUTABLE}_ir
    test_ir.cpp
    ${SOURCES}
)

add_executable(
    ${CURRENT_EXECUTABLE}_types
    test_types.cpp
    ${SOURCES}
)


target_include_directories(
        ${CURRENT_EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}
)
target_include_directories(
        ${CURRENT_EXECUTABLE} PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/grammar
)

# execute_process(COMMAND llvm-config-12 --libs all
#                 OUTPUT_VARIABLE llvm_libs)

llvm_map_components_to_libnames(
llvm_libs
x86info
x86asmparser
support core irreader target mc option codegen mcjit nativecodegen
)


# llvm_map_components_to_libnames(llvm_libs aarch64 aarch64asmparser aarch64codegen aarch64desc aarch64disassembler aarch64info aarch64utils aggressiveinstcombine all all-targets amdgpu amdgpuasmparser amdgpucodegen amdgpudesc amdgpudisassembler amdgpuinfo amdgpuutils analysis arm armasmparser armcodegen armdesc armdisassembler arminfo armutils asmparser asmprinter avr avrasmparser avrcodegen avrdesc avrdisassembler avrinfo binaryformat bitreader bitstreamreader bitwriter bpf bpfasmparser bpfcodegen bpfdesc bpfdisassembler bpfinfo cfguard codegen core coroutines coverage debuginfocodeview debuginfodwarf debuginfogsym debuginfomsf debuginfopdb demangle dlltooldriver dwarflinker engine executionengine frontendopenmp fuzzmutate globalisel hexagon hexagonasmparser hexagoncodegen hexagondesc hexagondisassembler hexagoninfo instcombine instrumentation interpreter ipo irreader jitlink lanai lanaiasmparser lanaicodegen lanaidesc lanaidisassembler lanaiinfo libdriver lineeditor linker lto mc mca mcdisassembler mcjit mcparser mips mipsasmparser mipscodegen mipsdesc mipsdisassembler mipsinfo mirparser msp430 msp430asmparser msp430codegen msp430desc msp430disassembler msp430info native nativecodegen nvptx nvptxcodegen nvptxdesc nvptxinfo objcarcopts object objectyaml option orcerror orcjit passes perfjitevents powerpc powerpcasmparser powerpccodegen powerpcdesc powerpcdisassembler powerpcinfo profiledata remarks riscv riscvasmparser riscvcodegen riscvdesc riscvdisassembler riscvinfo riscvutils runtimedyld scalaropts selectiondag sparc sparcasmparser sparccodegen sparcdesc sparcdisassembler sparcinfo support symbolize systemz systemzasmparser systemzcodegen systemzdesc systemzdisassembler systemzinfo tablegen target textapi transformutils vectorize webassembly webassemblyasmparser webassemblycodegen webassemblydesc webassemblydisassembler webassemblyinfo windowsmanifest x86 x86asmparser x86codegen x86desc x86disassembler x86info x86utils xcore xcorecodegen xcoredesc xcoredisassembler xcoreinfo)
target_link_libraries(${CURRENT_EXECUTABLE} ${GRAMMAR_LIB} ${llvm_libs})

target_include_directories(
        ${CURRENT_EXECUTABLE}_tests PRIVATE ${PROJECT_SOURCE_DIR}
)
target_include_directories(
        ${CURRENT_EXECUTABLE}_tests PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/grammar
)

target_include_directories(
        ${CURRENT_EXECUTABLE}_ir PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/grammar
)

target_include_directories(
        ${CURRENT_EXECUTABLE}_ir PRIVATE ${PROJECT_SOURCE_DIR}
)

target_include_directories(
        ${CURRENT_EXECUTABLE}_types PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/grammar
)

target_include_directories(
        ${CURRENT_EXECUTABLE}_types PRIVATE ${PROJECT_SOURCE_DIR}
)


target_link_libraries(${CURRENT_EXECUTABLE}_tests ${GRAMMAR_LIB} ${llvm_libs})

target_link_libraries(${CURRENT_EXECUTABLE}_ir ${GRAMMAR_LIB} ${llvm_libs})

target_link_libraries(${CURRENT_EXECUTABLE}_types ${GRAMMAR_LIB} ${llvm_libs})