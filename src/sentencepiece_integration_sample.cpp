#include <sentencepiece_processor.h>
#include <iostream>
#include <string>
#include <vector>

int main() {
    sentencepiece::SentencePieceProcessor processor;
    const auto status = processor.Load("/home/ubuntu/sentencepiece/python/test/test_model.model");
    if (!status.ok()) {
        std::cerr << status.ToString() << std::endl;
        return -1; // error
    }

    // Example of encoding text into SentencePiece tokens
    std::vector<std::string> pieces;
    processor.Encode("This is a test.", &pieces);
    for (const std::string &token : pieces) {
        std::cout << token << std::endl;
    }

    std::vector<int> encoded_ids;
    processor.Encode("This is a test.", &encoded_ids);
    for (const int &id : encoded_ids) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    // Example of decoding SentencePiece tokens into text
    std::vector<std::string> sp_pieces = { "▁This", "▁is", "▁a", "▁", "te", "st", "." };
    std::string text;
    processor.Decode(sp_pieces, &text);
    std::cout << text << std::endl;

    // Example of decoding SentencePiece token IDs into text
    std::vector<int> ids = { 284, 47, 11, 4, 15, 400, 6 };
    processor.Decode(ids, &text);
    std::cout << text << std::endl;

    return 0;
}