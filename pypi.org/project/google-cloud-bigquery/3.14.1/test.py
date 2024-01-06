import unittest
from google.cloud import bigquery


class TestQuery(unittest.TestCase):
    def test_answer(self):
        client = bigquery.Client()
        job = client.query('select 42 as answer')
        
        ret = [ row for row in job.result() ]

        assert(job.errors is None)
        self.assertEqual(len(ret), 1)
        self.assertEqual(ret[0]['answer'], 42)


    def test_failed(self):
        client = bigquery.Client()
        job = client.query('select missing')

        assert(job.errors is not None)

    
    def test_dataframe(self):
        client = bigquery.Client()
        job = client.query('select 42 as answer')

        df = job.to_dataframe()
        self.assertEqual(df.to_json(orient='records', lines=True).strip(),'{"answer":42}')