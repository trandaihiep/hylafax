/*	$Id$ */
/*
 * Copyright (c) 2007 iFAX Solutions, Inc.
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
#ifndef _Batch_
#define	_Batch_
 
#include "QLink.h"
#include "IOHandler.h"
#include "Job.h"
#include "DestInfo.h"


class Batch
  : public IOHandler
  , public QLink
{
    public:
	Batch(DestInfo& d, const char* n, const char* type);
	~Batch(void);

	void childStatus(pid_t, int);

	void startPrepare(Job& job, pid_t);
	void startSend(pid_t);

	Job& firstJob();
	Job& lastJob();

	u_int jobCount () const;

	operator DestInfo&() const	{ return di; }
	operator FaxMachineInfo&() const{ return di.getInfo(dest); }

	QLink		jobs;
	DestInfo&	di;
	fxStr		dest;
	time_t		start;

	Modem*		modem;
	Batch*		dnext;
	fxStr		jobtype;



    private:
	pid_t		pid;
	Job*		prepareJob;
};

#endif
