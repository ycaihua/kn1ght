#variables
CC = gcc
CFLAGS= -g -Wall
TARGET = kn1ght
#commands
RM = rm -f
RMDIR = rm -rf
CP = cp
CPDIR = cp -a
MKDIR_RX = install -dm755
MKDIR_RO = install -dm644
INSTALL_RX = install -Dm755
INSTALL_RO = install -Dm644
# locations
PREFIX = /usr
SHAREDIR = $(DESTDIR)$(PREFIX)/share
BINDIR = $(DESTDIR)$(PREFIX)/bin
LICENSEDIR = $(SHAREDIR)/licenses

$(TARGET): $(TARGET).c
	$(CC) -o $(TARGET) $(TARGET).c

# to see all compilation errors & warnings
verbose:
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

#linux only
clean:
	$(RM) $(TARGET)

install:
	# make
	$(CC) -o $(TARGET) $(TARGET).c
	# install target to bin
	$(INSTALL_RX) $(TARGET) $(BINDIR)/$(TARGET)
	# install license
	$(MKDIR_RX) $(LICENSEDIR)/$(TARGET)
	$(INSTALL_RO) LICENSE $(LICENSEDIR)/$(TARGET)

uninstall:
	# remove executable from path
	$(RM) $(BINDIR)/$(TARGET)
	# remove license
	$(RMDIR) $(LICENSEDIR)/$(TARGET)
