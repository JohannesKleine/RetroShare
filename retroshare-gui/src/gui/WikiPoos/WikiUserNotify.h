#pragma once

#include <retroshare/rswiki.h>
#include "gui/common/UserNotify.h"

/**
 * Handles Wiki notifications (unread counts) in the main UI
 */
class WikiUserNotify : public UserNotify
{
    Q_OBJECT

public:
    WikiUserNotify(RsWiki *wiki, QObject *parent = nullptr);
    virtual ~WikiUserNotify();

    /* Processes incoming events to trigger UI notification signals */
    virtual void handleEvent(std::shared_ptr<const RsEvent> event) override;

private:
    uint32_t mEventHandlerId;
};
