const createMetrics = function createMetrics(text){
    const obj = {
        totalLetters: 0,
        totalNonLetters: 0,
        totalWords: 0,
        totalVowels: 0,
        totalConsonants: 0,
        uniqueWords: 0,
        longWords: 0,
        averageWordLength: 0,
        wordOccurrences: null
    };
    if (typeof text == 'string'){
        let lowerCaseText = text.toLowerCase();
        
        
        
        for(var i in lowerCaseText){
                if(lowerCaseText[i].match(/[a-z]/)){
                    obj.totalLetters = obj.totalLetters + 1;
                    if(lowerCaseText[i]==='a'||lowerCaseText[i]==='e'||lowerCaseText[i]==='o'||lowerCaseText[i]==='u'||lowerCaseText[i]==='i'){
                        obj.totalVowels = obj.totalVowels + 1;
                    }
                    
                }
                else
                {
                    obj.totalNonLetters = obj.totalNonLetters + 1;
                }
            }
            lowerCaseText = lowerCaseText.replace(/'+/gi, '')
            let words = lowerCaseText.replace(/[^a-z]/gi,' ').replace(/\s+/gi, '+').split('+');
            let sumWordLength = 0;
            for(var i in words){
                sumWordLength = sumWordLength + words[i].length;
                if(words[i].length>=6)
                    obj.longWords = obj.longWords + 1;
            }
            var charMap = new Object();
            for (var char in words){
                charMap[words[char]] = 0;
            }
            for (var char in words){
                charMap[words[char]] = charMap[words[char]]+1;
            }
            obj.wordOccurrences = charMap;
            obj.totalWords = words.length;
            obj.averageWordLength = sumWordLength/obj.totalWords;
            obj.totalConsonants = obj.totalLetters - obj.totalVowels;
            words = Array.from(new Set(words))
            obj.uniqueWords =  words.length;
        //regex taken from https://www.webmasterworld.com/javascript/3667438.htm
       
    }
    else {
        throw  `Input argument is not a string.`;
    }
    return obj;
}

module.exports =  {
    firstName: "Hadia", 
    lastName: "Hameed", 
    studentId: "10440803",
    createMetrics
}