
AM_CFLAGS=-DBUILDING_AQHBCI @visibility_cflags@

INCLUDES = -I$(aqbanking_symlinkdir) $(all_includes) \
  -I$(srcdir)/../joblayer \
  -I$(srcdir)/../msglayer \
  -I$(srcdir)/../banking \
  -I$(srcdir)/../applayer \
  -I$(srcdir)/..

noinst_LTLIBRARIES=libhbciadmjobs.la

noinst_HEADERS=\
  jobgetkeys_l.h jobgetkeys_p.h \
  jobsendkeys_l.h jobsendkeys_p.h \
  jobtan_l.h jobtan_p.h \
  jobgetsepainfo_l.h jobgetsepainfo_p.h \
  jobgetsysid_l.h jobgetsysid_p.h

libhbciadmjobs_la_SOURCES=\
  jobgetkeys.c \
  jobsendkeys.c \
  jobtan.c \
  jobgetsepainfo.c \
  jobgetsysid.c


sources:
	for f in $(libhbciadmjobs_la_SOURCES); do \
	  echo $(subdir)/$$f >>$(top_srcdir)/i18nsources; \
	done
	for d in $(SUBDIRS); do \
	  $(MAKE) -C $$d sources; \
	done

xmlfiles=\
  $(srcdir)/jobgetkeys.xml \
  $(srcdir)/jobsendkeys.xml \
  $(srcdir)/jobtan.xml \
  $(srcdir)/jobgetsepainfo.xml \
  $(srcdir)/jobgetsysid.xml


EXTRA_DIST=$(xmlfiles)

adminjobs.xml: $(xmlfiles)
	$(XMLMERGE) -v --compact -o $@ $(xmlfiles)

all-local: adminjobs.xml

CLEANFILES = adminjobs.xml


cppcheck:
	for f in $(libhbciadmjobs_la_SOURCES); do \
	  cppcheck --force $$f ; \
	done





