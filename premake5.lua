workspace("SimpleGame")
architecture("x64")

configurations({
	"Debug",
	"Release",
	"Dist",
})

include("Engine")
include("App")
