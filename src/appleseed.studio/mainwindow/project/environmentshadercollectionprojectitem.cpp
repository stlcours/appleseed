
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010 Francois Beaune
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

// Interface header.
#include "environmentshadercollectionprojectitem.h"

// appleseed.studio headers.
#include "mainwindow/project/environmentshaderprojectitem.h"
#include "mainwindow/project/projectbuilder.h"

// appleseed.foundation headers.
#include "foundation/utility/foreach.h"

using namespace foundation;
using namespace renderer;

namespace appleseed {
namespace studio {

EnvironmentShaderCollectionProjectItem::EnvironmentShaderCollectionProjectItem(
    ProjectBuilder&                     project_builder,
    const EnvironmentShaderContainer&   environment_shaders)
  : CollectionProjectItemBase("Environment Shaders")
  , m_project_builder(project_builder)
{
    for (const_each<EnvironmentShaderContainer> i = environment_shaders; i; ++i)
        add_item(*i);
}

QMenu* EnvironmentShaderCollectionProjectItem::get_context_menu() const
{
    return 0;
}

void EnvironmentShaderCollectionProjectItem::add_item(const EnvironmentShader& environment_shader)
{
    addChild(new EnvironmentShaderProjectItem(environment_shader));
}

}   // namespace studio
}   // namespace appleseed
