default: cmake-debug debug
jenkins: clean cmake-debug cmake-release debug release test test-algorithm coverage lint

cmake-debug:
	mkdir -p build/debug && \
	cd build/debug && \
	cmake -DCMAKE_BUILD_TYPE=Debug ../../

cmake-release:
	mkdir -p build/release && \
	cd build/release && \
	cmake -DCMAKE_BUILD_TYPE=Release ../../

debug:
	cd build/debug && $(MAKE)

release:
	cd build/release && $(MAKE)

test:
	cd build/debug && \
	./unittest --gtest_output=xml:../../gtest_unittest.xml

test-algorithm:
	cd build/release && \
	./happy_family --gtest_output=xml:../../gtest_happy_family.xml

coverage:
	gcovr -r . -e 3rdparty/ -e src/ -e unittest/ --xml >coverage.xml

lint:
	# cppcheck
	cppcheck --enable=all --check-config --inconclusive --xml --xml-version=2 src 2> cppcheck-result.xml
	# cpplint
	#find src/ -type d \( -path $(GEN_DIR) \) -prune -o \
	#-exec sh -c  "python scripts/codestyle/cpp/cpplint/cpplint.py --linelength=120 --counting=detailed --output=vs7 '{}' 1>>cpplint-result.xml 2>>cpplint-result.xml" \;

clean:
	rm -rf build/
	rm -f *.xml
