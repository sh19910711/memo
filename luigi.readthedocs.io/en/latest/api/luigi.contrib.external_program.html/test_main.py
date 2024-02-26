import luigi
from unittest import TestCase
from main import CreateFile
from datetime import datetime


class TestCreateFile(TestCase):
    def test_run(self):
        today = datetime.today().date()
        luigi.run(['CreateFile', '--date', today.isoformat()], local_scheduler=True)
        t = CreateFile(date=today)
        with t.output().open() as f:
            self.assertEqual('bar', f.read().strip())