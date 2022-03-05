# SixMansPlugin
## TODO:
* Cvars for every variable, use a define and prefix "s"
* Modernize and modularize as much as possible
*	Imgui:
	*	Settings menu
		*	Default map
		*	Enable/disable
			*	"Soft" disable- unregister cvars and hooks, don't unload
		*	Auto go to lobby
		*	Retry go to lobby after some seconds after failure
		*	Local server ip
		*	Default region
		*	Show lobby info on toast option
		*	Auto tab-in once server receives lobby info
	*	Toast notification
		*	Button for join/create
		*	Timers for retry
		*	In-action toast
*	Local server that listens for match info via url
	*	Needs to decode a url for info
	*	Standardize url format
	*	Fancy html page?
*	Implement BMAPI create/join lobby as backend
