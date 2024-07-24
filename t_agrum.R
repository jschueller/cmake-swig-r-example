dyn.load(paste("base", .Platform$dynlib.ext, sep=""))
source("base.R")
cacheMetaData(1)

p <- randomProba()
print(p)

b <- DiscreteVariable("B")
# print(b)
