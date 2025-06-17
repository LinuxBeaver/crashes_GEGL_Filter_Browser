/* This file is an image processing operation for GEGL
 *
 * GEGL is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * GEGL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GEGL; if not, see <https://www.gnu.org/licenses/>.
 *
 * Credit to Øyvind Kolås (pippin) for major GEGL contributions

 An example of a crash in GEGL filter browser
 */

#include "config.h"
#include <glib/gi18n-lib.h>


#ifdef GEGL_PROPERTIES




#define p1 \
"  nop   "\

#define p2 \
" nop  "\

property_enum (dropdownlist, _("Drop down list select of nothing:"),
    nichepluginexample, niche_pluginexample,
    part1)
   description  (_("description here"))



/*If you accidentially name part1 as "part2" you get the crash
 * the crash results in GEGL filter browser not opening correctly*/

enum_start (niche_pluginexample)
  enum_value (part1,      "part2", /*part1*/
              N_("NO CONTENT"))
  enum_value (part2,      "part2",
              N_("NO CONTENT"))
enum_end (nichepluginexample)

#else

#define GEGL_OP_META
#define GEGL_OP_NAME     examplecrash
#define GEGL_OP_C_SOURCE examplecrash.c

#include "gegl-op.h"

typedef struct
{
 GeglNode *input;
 GeglNode *a;
 GeglNode *b;
 GeglNode *output;
}State;


static void attach (GeglOperation *operation)
{
  GeglNode *gegl = operation->node;
  GeglProperties *o = GEGL_PROPERTIES (operation);

  State *state = o->user_data = g_malloc0 (sizeof (State));

  state->input    = gegl_node_get_input_proxy (gegl, "input");
  state->output   = gegl_node_get_output_proxy (gegl, "output");

  state->a    = gegl_node_new_child (gegl,
                                  "operation", "gegl:gegl", "string", p1,
                                  NULL);

  state->b    = gegl_node_new_child (gegl,
                                  "operation", "gegl:gegl", "string", p2,
                                  NULL);

}

static void update_graph (GeglOperation *operation)
{
  GeglProperties *o = GEGL_PROPERTIES (operation);
  State *state = o->user_data;
  if (!state) return;

switch (o->dropdownlist) {
        break;
    case part1:
  gegl_node_link_many (state->input,  state->a,  state->output,  NULL);
        break;
    case part2:
  gegl_node_link_many (state->input,  state->b,  state->output,  NULL);

    }
  }

static void
gegl_op_class_init (GeglOpClass *klass)
{
  GeglOperationClass *operation_class;
GeglOperationMetaClass *operation_meta_class = GEGL_OPERATION_META_CLASS (klass);
  operation_class = GEGL_OPERATION_CLASS (klass);

  operation_class->attach = attach;
  operation_meta_class->update = update_graph;

  gegl_operation_class_set_keys (operation_class,
    "name",        "example:crash",
    "title",       _("Example Crash"),
    "reference-hash", "blik375fd",
    "description", _("Exampple of a crash that happens ion"),
    "gimp:menu-path", "<Image>/Filters/example crash",
    "gimp:menu-label", _("Example crash with GEGL filter browser..."),
    NULL);
}

#endif
