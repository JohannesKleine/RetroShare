#include <retroshare/rsevents.h>
#include "WikiUserNotify.h"
#include "util/qtthreadsutils.h"

WikiUserNotify::WikiUserNotify(RsWiki */*wiki*/, QObject *parent)
    : UserNotify(parent), mEventHandlerId(0)
{
    /* Get the dynamic event type ID for Wiki */
    RsEventType wikiEventType = (RsEventType)rsEvents->getDynamicEventType("GXS_WIKI");

    /* Register to listen for wiki events and forward them to the GUI thread */
    rsEvents->registerEventsHandler([this](std::shared_ptr<const RsEvent> event) {
        RsQThreadUtils::postToObject([=]() { handleEvent(event); }, this);
    }, mEventHandlerId, wikiEventType);
}

WikiUserNotify::~WikiUserNotify()
{
    if (rsEvents && mEventHandlerId > 0) {
        rsEvents->unregisterEventsHandler(mEventHandlerId);
    }
}

void WikiUserNotify::handleEvent(std::shared_ptr<const RsEvent> event)
{
    const RsGxsWikiEvent *e = dynamic_cast<const RsGxsWikiEvent *>(event.get());
    
    /* If a new page version is detected, tell the UI to update the counters */
    if (e && e->mWikiEventCode == RsWikiEventCode::UPDATED_SNAPSHOT) {
        emit notifyUser();
    }
}
