import luigi
import os
from pathlib import Path
from luigi.contrib.external_program import ExternalProgramTask


class CreateFile(ExternalProgramTask):
    date = luigi.DateParameter()
    capture_output = False

    def output(self):
        return luigi.LocalTarget(f'./tmp/{self}/test.txt')
    
    def program_environment(self):
        return {'FOO': 'bar'}

    def program_args(self):
        p = Path(self.output().path)
        os.makedirs(p.parent, exist_ok=True)
        return ['bash', '-c', f'echo $FOO > "{p}"']


# python3 -m luigi --module main --local-scheduler Main --date=2024-02-26
class Main(luigi.WrapperTask):
    date = luigi.DateParameter()

    def requires(self):
        yield CreateFile(date=self.date)