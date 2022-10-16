
# use another file 
to use another file in main. You have to create two file called ``xxx.h`` and ``xxx.cpp`` file (two file have to be same name)

the ``xxx.h`` file should looks like this;
```
#ifndef XXX_H
#define XXX_H

{ YOUR CODE will be in here }

#endif
```

the ``xxx.cpp`` file implements the ``xxx.h`` file.

for this include ``xxx.h``

```
#include "xxx.h";
```

after including, implement method.