import nltk

class Analyzer():
    """Implements sentiment analysis."""
    
  
   
    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
       
        self.keys = {};
        with open(positives) as f:
             for line in f:
                if(line[0] !=';'):
                    self.keys[line] = 1;
                
        
        
        with open(negatives) as f:
             for line in f:
                if(line[0] !=';'):
                    self.keys[line] = -1;
                    
        
        
    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        score = 0;
        for word in tokens:
            word += "\n";
            if(word in self.keys):
                score +=  self.keys.get(word);
        return score;
