GLOBAL _JS_CPU_Enable_cache  ;void JS_CPU_Enable_cache(void)
GLOBAL _JS_CPU_Disable_cache	;void JS_CPU_Disable_cache(void)

CR0_CACHE_DISABLE	EQU		0X60000000
CR0_CACHE_ENABLE	EQU		0X9FFFFFFF

_JS_CPU_Enable_cache:
	MOV		EAX,CR0
	AND		EAX,CR0_CACHE_ENABLE
	MOV		CR0,EAX
	RET



_JS_CPU_Disable_cache:
	MOV		EAX,CR0
	OR		EAX,CR0_CACHE_DISABLE
	MOV		CR0,EAX
	RET