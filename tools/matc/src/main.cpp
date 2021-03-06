/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdlib.h>

#include <iostream>
#include <memory>

#include "matc/Compiler.h"
#include "matc/CommandlineConfig.h"
#include "matc/MaterialCompiler.h"
#include "matc/PostprocessMaterialCompiler.h"

using namespace matc;

int main(int argc, char** argv) {
    CommandlineConfig parameters(argc, argv);
    if (!parameters.isValid()) {
        std::cerr << "Invalid parameters." << std::endl;
        return EXIT_FAILURE;
    }

    std::unique_ptr<Compiler> compiler = nullptr;
    switch (parameters.getMode()) {
        case CommandlineConfig::Mode::MATERIAL:
            compiler.reset(new MaterialCompiler());
            break;
        case CommandlineConfig::Mode::DEPTH:
            // this option is obsolete
            return EXIT_SUCCESS;
        case CommandlineConfig::Mode::POSTPROCESS:
            compiler.reset(new PostprocessMaterialCompiler());
            break;
    }

    if (!compiler->start(parameters)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
