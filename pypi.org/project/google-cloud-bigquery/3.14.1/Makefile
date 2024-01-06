.PHONY: test
test:
	docker build -t tmp ./
	docker run --rm -e GOOGLE_CLOUD_PROJECT -ti tmp \
		python3 -m unittest