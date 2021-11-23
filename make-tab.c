#include <yed/plugin.h>

void insert_tab( yed_event *ye );

int yed_plugin_boot( yed_plugin *self )
{
    YED_PLUG_VERSION_CHECK();

    yed_event_handler yeh;
    yeh.kind = EVENT_BUFFER_PRE_INSERT;
    yeh.fn = insert_tab;

    yed_plugin_add_event_handler( self, yeh );

    return 0;
}

void insert_tab( yed_event *ye )
{
    if ( ye->key == TAB )
    {
        if ( ye->buffer->ft == yed_get_ft( "Make" ) )
        {
            char st[1024];

            sprintf( st, "%d", SHIFT_TAB );

            YEXE( "insert", st );

            ye->cancel = 1;
        }
    }
}
