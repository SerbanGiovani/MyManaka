SFM_CosplayPatch:

Allows patching values in the RCosplayParts class from JSON.
I wrote this because I felt certain Cosplay items needed tweaking, namely the hoodie and the summer cardigan, which now both cover Manaka's butt as they appear to.

Should work for all cosplay items and all values.

The names to use for each entry are the RCosplayParts.NameKey value (you can print them in the BepInEx terminal by pressing F9 in the Custom Missions mod).

MODIFIABLE VALUES: (non-exhaustive)

	-HiddenPartsType: Possible values:
		["Boobs", "Hip", "Genitals", "SideOrBackUpperBody", "HipCrouch"]
		Each value included adds the appropriate flag to the Cosplay item.
		Placing a - sign at the beginning of a string removes the flag instead. (i.e. ["-HipCrouch"] removes the HipCrouch flag)
		
	-int DokidokiBonus: integer, Arousal Bonus of the Cosplay item. (can be negative)
	-int StrangeBonus: integer, Detection Bonus of the Cosplay item. (can be negative)
	-int RPBonus: integer, RP Bonus of the Cosplay item. (can be negative)
		
	-float LookHiddenPartMaxStrange: decimal (range 0.0 - 1.0), if there are hidden body parts,
		then setting this value will allow suspicion to climb to a percentage from looking at the hidden values
		(i.e. setting it to 0.7 will allow suspicion to climb to 70% of max)
			
	-bool IsEyeMaskEffect: true or false, haven't tested yet, but based on the name, if it's true, this Cosplay item will work like a blindfold.
	
	
Datatypes cheatsheet, if anyone needs it:
	-strings - text.
	-int - integer numbers (no decimals)
	-float/double - decimal numbers or very large numbers
	-bool - Boolean values (either true or false)
	
	
KNOWN ISSUES:
	-The patch is applied roughly once a second instead of a single time on asset loading (because I couldn't find where assets are loaded).
		It shouldn't noticeably affect performance, but let me know if it does.
	-Base game bug, but more noticeable with my default settings: if any part of the front of the body is exposed, the game treats the entire front as exposed.
		This is outside the scope of this plugin, but I'm working on a fix as a separate plugin.