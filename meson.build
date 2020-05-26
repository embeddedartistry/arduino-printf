project('Arduino-Printf', 'cpp',
  version : '1.1.0',
  license : 'MIT',
  default_options : ['buildtype=minsize',
                     'b_lto=true',
                     'cpp_std=gnu++11',
                     'b_staticpic=false',
                     ],
  )

# This dependency is used when using libPrintf in unit tests on the host machine
libPrintf_test_dep = declare_dependency(
	include_directories: include_directories('extras/printf', 'extras/test', is_system: true),
	sources: files('extras/printf/printf.c'),
)

# The library itself is only available when cross-compiled
# for AVR due to the use of Arduino Core
if meson.is_cross_build()
	if host_machine.cpu_family() != 'avr'
		error('The Meson build for this library is only configured for AVR processors')
	endif

	arduinocore = subproject('arduinocore-avr')
	arduinocore_dep = arduinocore.get_variable('arduinocore_dep')
	arduinocore_main_dep = arduinocore.get_variable('arduinocore_main_dep')

	##################
	# Library Target #
	##################
	libPrintf = static_library('Printf',
		'src/LibPrintf.cpp',
		include_directories: include_directories('src'),
		dependencies: arduinocore_dep,
		build_by_default: meson.is_subproject() == false
	)

	#######################
	# External Dependency #
	#######################
	libPrintf_dep = declare_dependency(
		include_directories: include_directories('src', is_system: true),
		link_with: libPrintf,
	)

	##########################
	# Example Sketch Targets #
	##########################
	if meson.is_subproject() == false
		# Compile example applications
		executable('default_to_serial',
			files('extras/sketch_cpp/default_to_serial.cpp'),
			dependencies: [
				libPrintf_dep,
				arduinocore_dep,
				arduinocore_main_dep,
			],
			install: false
		)

		executable('override_putchar',
			files('extras/sketch_cpp/override_putchar.cpp'),
			dependencies: [
				libPrintf_dep,
				arduinocore_dep,
				arduinocore_main_dep,
			],
			install: false
		)

		if host_machine.cpu() == 'atmega2560'
			# Serial1 is only usable on the Mega, not the Uno
			executable('specify_print_class',
				files('extras/sketch_cpp/specify_print_class.cpp'),
				dependencies: [
					libPrintf_dep,
					arduinocore_dep,
					arduinocore_main_dep,
				],
				install: false
			)
		endif
	endif
endif
