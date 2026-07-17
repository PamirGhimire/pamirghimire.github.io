#ifndef IFACE_H
#define IFACE_H

#define IFACE_SHM_NAME "/iface_example"

struct iface
{
    float x;
    float y;/* data */
};

bool initialize(iface* handle);
bool update(iface* handle);

#endif
