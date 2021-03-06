/*	$Id$ */
/*
 * Copyright (c) 1990-1996 Sam Leffler
 * Copyright (c) 1991-1996 Silicon Graphics, Inc.
 * HylaFAX is a trademark of Silicon Graphics
 *
 * Permission to use, copy, modify, distribute, and sell this software and 
 * its documentation for any purpose is hereby granted without fee, provided
 * that (i) the above copyright notices and this permission notice appear in
 * all copies of the software and related documentation, and (ii) the names of
 * Sam Leffler and Silicon Graphics may not be used in any advertising or
 * publicity relating to the software without the specific, prior written
 * permission of Sam Leffler and Silicon Graphics.
 * 
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY 
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  
 * 
 * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR
 * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF 
 * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE 
 * OF THIS SOFTWARE.
 */
#ifndef _UUCPLOCK_
#define	_UUCPLOCK_
/*
 * UUCP Locking Support.
 */
#include <unistd.h>
#include "Str.h"

class UUCPLock {
private:
    fxStr	file;			// lock file pathname
    mode_t	mode;			// lock file mode
    bool	locked;			// is lock currently held

    static uid_t UUCPuid;
    static gid_t UUCPgid;
    static void setupIDs();

    static time_t lockTimeout;

    bool	create();		// create lock file
    bool	isNewer(time_t age);	// is lock file newer than age
    bool	ownerExists(int fd);	// does owning process exist
protected:
    UUCPLock(const fxStr& pathname, mode_t mode);

    virtual void setPID(pid_t) = 0;
    virtual bool writeData(int fd) = 0;
    virtual bool readData(int fd, pid_t& pid) = 0;
public:
    virtual ~UUCPLock();

    static uid_t getUUCPUid();
    static gid_t getUUCPGid();
    static void setLockTimeout(time_t);

    static UUCPLock* newLock(		// public interface to create a lock
	const char* type,		// lock file type
	const fxStr& prefix,		// lock file directory+prefix
	const fxStr& device,		// device pathname
	mode_t mode);			// file creation mode

    bool	isLocked() const;	// device is locked
    bool	lock();			// lock device
    void	unlock();		// unlock device
    bool	check();		// check if lock exists
    bool	setOwner(pid_t);	// force process owner identity
};

inline bool UUCPLock::isLocked() const	{ return locked; }
#endif /* _UUCPLOCK_ */
